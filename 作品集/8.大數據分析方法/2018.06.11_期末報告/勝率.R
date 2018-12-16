library(readr)
library(elo)
library(dplyr)
dataset<-read_csv("C:/Users/Peter/Desktop/results.csv")
###新增贏的結果
dataset <- dataset%>%
  mutate(win=if_else(home_score > away_score, home_team,
             if_else(home_score == away_score,"drew", away_team)))
###選取所需的欄位
team<-c("Russia", "Germany", "Brazil", "Portugal", "Argentina", "Belgium",
        "Poland", "France", "Spain", "Peru", "Switzerland", "England",
        "Colombia", "Mexico", "Uruguay", "Croatia", "Denmark", "Iceland",
        "Costa Rica", "Sweden", "Tunisia", "Egypt", "Senegal", "Iran",
        "Serbia", "Nigeria", "Australia", "Japan", "Morocco", "Panama",
        "Korea Republic", "Saudi Arabia")
WCteam_win<-dataset%>%
  filter(home_team%in% team|
           away_team%in% team)%>%
  select(date, home_team, away_team,win)
###
winrate=c()
for(i in 1:32){
  select_team=team[i]
  result=WCteam_win%>%
    filter(home_team==select_team|
             away_team==select_team)
  win_result=result%>%
    filter(win==select_team)
  total_count=nrow(result)
  win_count=nrow(win_result)
  win_rate=win_count/total_count
  winrate=c(winrate,win_rate)
}
team_winrate=data.frame(隊伍名稱=team,
                        勝率=winrate,
                        stringsAsFactors=F)

team_winrate[[31,1]]<-"South Korea"
###merge()
WCteam_info<-read_csv("C:/Users/Peter/Desktop/WorldCupGroup.csv")
WCteam<-merge(team_winrate,WCteam_info,by.x="隊伍名稱",by.y="英文名稱")%>%
  arrange(組別,抽籤檔次)
WCteam$勝率<-round(WCteam$勝率,digits=2)
###作圖
library(ggplot2)
chart1<-
  ggplot(data=WCteam,
         aes(x=reorder(中文名稱,-勝率),y=勝率))+
  geom_bar(stat = "identity",fill = "cornflowerblue")+
  geom_text(aes(label=WCteam$勝率),color = "blue", vjust=-0.5)+
  theme_light()+
  labs(title="世界盃參賽國家勝率(所有比賽)條狀圖",x="國家",y="勝率")+
  theme(plot.title = element_text(size = 20, hjust = 0.5))+
  theme(axis.text.x = element_text(size = 20, angle = 90, hjust = 1,vjust=0.4))
chart1
###面量圖
library(choroplethr)
library(choroplethrMaps)
WCchart2<-WCteam%>%
  select(隊伍名稱,勝率)
colnames(WCchart2)<-c("region","value")
WCchart2$region<-tolower(WCchart2$region)
chart2<-
  country_choropleth(WCchart2)+
  scale_fill_brewer(palette=7,na.value="grey")+
  labs(title="世界盃參賽國家勝率(所有比賽)面量圖")+
  theme(plot.title = element_text(size = 20, hjust = 0.5))
chart2

# write.csv(WCchart2,file="C:/Users/Peter/Desktop/WC_teams_winrate.csv",
#           row.names = F,col.names = T,fileEncoding="UTF-8")