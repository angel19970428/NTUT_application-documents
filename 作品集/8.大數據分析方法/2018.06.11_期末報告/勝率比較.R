library(readr)
library(dplyr)
library(ggplot2)
winrate<-read_csv("C:/Users/Peter/Desktop/WC_teams_winrate.csv")
FIFAwinrate<-read_csv("C:/Users/Peter/Desktop/WC_teams_FIFAwinrate.csv")
teams<-read_csv("C:/Users/Peter/Desktop/WorldCupGroup.csv")
teams$英文名稱<-tolower(teams$英文名稱)
result<-merge(winrate,FIFAwinrate,by="region")
result<-merge(result,teams,by.x="region",by.y="英文名稱")%>%
  select(1:4)
chart<-ggplot(data=result, aes(x=value.x, y=value.y))+
  geom_point(shape=17,color="red",size=2)+
  labs(title="勝率比較圖",x="所有比賽勝率",y="世界盃勝率")+
  geom_text(aes(label=result$中文名稱.x),size=6,color="blue",vjust=-0.5)+
  theme_light()+
  theme(plot.title = element_text(size = 20, hjust = 0.5))
chart