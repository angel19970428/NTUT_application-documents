library(readr)
teams<-read_csv("C:/Users/Peter/Desktop/teams.csv")
###united states,united kingdom
grep("Burma",teams$team)
teams[[2,1]]<-"united kingdom"
teams[[5,1]]<-"united states of america"
teams[[85,1]]<-"united republic of tanzania"
teams[[88,1]]<-"democratic republic of the congo"
teams[[96,1]]<-"South Korea"
teams[[103,1]]<-"myanmar"
teams[[111,1]]<-"guinea bissau"
teams[[119,1]]<-"North Korea"
teams[[132,1]]<-"republic of congo"
teams[[220,1]]<-"republic of serbia"
teams[[221,1]]<-"bosnia and herzegovina"
teams[[227,1]]<-"the bahamas"
library(dplyr)
result<-teams%>%
  select(team,elo)
colnames(result)<-c("region","value")
library(choroplethr)
library(choroplethrMaps)
library(ggplot2)
result$region<-tolower(result$region)
chart<-
  country_choropleth(result)+
  scale_fill_brewer(palette=7,na.value="grey")+
  labs(title="足球實力面量圖")+
  theme(plot.title = element_text(size = 20, hjust = 0.5))
chart