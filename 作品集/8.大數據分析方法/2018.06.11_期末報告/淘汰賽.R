# library(readr)
# library(elo)
# library(dplyr)
# WC_teams<-read_csv("C:/Users/Peter/Desktop/WC_teams2.csv")
Hometeam<-"Brazil"
Awayteam<-"Spain"
home <- subset(WC_teams, team == Hometeam)$elo
away <- subset(WC_teams, team == Awayteam)$elo
homewin<-elo.prob(home,away)
win=ifelse(homewin>0.5,1,0)
###
teamA_elo <- subset(WC_teams, team == Hometeam)$elo
teamB_elo <- subset(WC_teams, team == Awayteam)$elo

new_elo <- elo.calc(wins.A = win,
                    elo.A = teamA_elo,
                    elo.B = teamB_elo,
                    k = 30)
teamA_new_elo <- new_elo[1, 1]
teamB_new_elo <- new_elo[1, 2]

WC_teams <- WC_teams %>%
  mutate(elo = if_else(team == Hometeam, teamA_new_elo,
                       if_else(team == Awayteam, teamB_new_elo, elo)))

print(homewin)
write.csv(WC_teams,file="C:/Users/Peter/Desktop/WC_teams3.csv",
          row.names = F,col.names = T,fileEncoding="UTF-8")