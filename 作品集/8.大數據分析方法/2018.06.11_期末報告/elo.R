library(readr)
library(elo)
library(dplyr)
dataset<-read_csv("C:/Users/Peter/Desktop/results.csv")
###最大比分紀錄
dataset %>%
  select(date, home_team, away_team, home_score, away_score) %>%
  mutate(total_goals = home_score + away_score) %>%
  arrange(-total_goals) %>%
  head(1)
##         date home_team      away_team home_score away_score total_goals
## 1 2001-04-11 Australia American Samoa         31          0          31
###找出所有隊
teams <- data.frame(team = unique(c(dataset$home_team, dataset$away_team)))
###設定每隊Elo初始值
teams <- teams %>%
  mutate(elo = 1500)
###有參加世界盃為1，沒有為0
teams<-teams%>%
  mutate(join=if_else(
    teams$team%in% 
      c("Russia", "Germany", "Brazil", "Portugal", "Argentina", "Belgium",
        "Poland", "France", "Spain", "Peru", "Switzerland", "England",
        "Colombia", "Mexico", "Uruguay", "Croatia", "Denmark", "Iceland",
        "Costa Rica", "Sweden", "Tunisia", "Egypt", "Senegal", "Iran",
        "Serbia", "Nigeria", "Australia", "Japan", "Morocco", "Panama",
        "Korea Republic", "Saudi Arabia"), 1,0))
###新增比賽結果欄位(1:主隊獲勝,0.5:平手,0:客隊獲勝)
dataset <- dataset%>%
  mutate(result=if_else(home_score > away_score, 1,
                  if_else(home_score == away_score, 0.5, 0)))
###只選我們要的欄位
matches <- dataset%>%
  select(date, home_team, away_team, result) %>%
  arrange(date)
###計算排名
for (i in seq_len(nrow(matches))) {
  match <- matches[i, ]
  
  #還沒比賽前的elo分數
  teamA_elo <- subset(teams, team == match$home_team)$elo
  teamB_elo <- subset(teams, team == match$away_team)$elo
  
  #新的elo分數
  new_elo <- elo.calc(wins.A = match$result,
                      elo.A = teamA_elo,
                      elo.B = teamB_elo,
                      k = 30)
  
  #The results come back as a data.frame
  #A隊在[1,1]
  #B隊在[1,2]
  teamA_new_elo <- new_elo[1, 1]
  teamB_new_elo <- new_elo[1, 2]
  
  #更新elo分數到teams
  teams <- teams %>%
    mutate(elo = if_else(team == match$home_team, teamA_new_elo,
                 if_else(team == match$away_team, teamB_new_elo, elo)))
}
###看排名
teams %>%
  arrange(desc(elo)) %>%
  head()
#####################################################################
####2018FIFA World Cup
WC_teams <- teams %>%
  filter(team %in% c("Russia", "Germany", "Brazil", "Portugal", "Argentina", "Belgium",
                     "Poland", "France", "Spain", "Peru", "Switzerland", "England",
                     "Colombia", "Mexico", "Uruguay", "Croatia", "Denmark", "Iceland",
                     "Costa Rica", "Sweden", "Tunisia", "Egypt", "Senegal", "Iran",
                     "Serbia", "Nigeria", "Australia", "Japan", "Morocco", "Panama",
                     "Korea Republic", "Saudi Arabia")) %>%
  arrange(desc(elo))
WC_teams
###世界盃遺珠
meanelo<-mean(WC_teams$elo)
teams %>%
  filter(elo > meanelo, !team %in% WC_teams$team)
###開幕戰
russia <- subset(WC_teams, team == "Russia")$elo
saudi_arabia <- subset(WC_teams, team == "Saudi Arabia")$elo
elo.prob(russia, saudi_arabia)
###兩強對打
france <- subset(WC_teams, team == "France")$elo
argentina <- subset(WC_teams, team == "Argentina")$elo
elo.prob(france, argentina)
###強打弱
Japan <- subset(teams, team == "Japan")$elo
Paraguay <- subset(teams, team == "Paraguay")$elo
elo.prob(Japan, Paraguay)

# write.csv(WC_teams,file="C:/Users/Peter/Desktop/WC_teams.csv",
#           row.names = F,col.names = T,fileEncoding="UTF-8")
# write.csv(teams,file="C:/Users/Peter/Desktop/teams.csv",
#           row.names = F,col.names = T,fileEncoding="UTF-8")


  
