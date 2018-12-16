ChineseName<-c("俄羅斯","沙烏地阿拉伯","埃及","烏拉圭",
               "葡萄牙","西班牙","摩洛哥","伊朗",
               "法國","澳洲","祕魯","丹麥",
               "阿根廷","冰島","克羅埃西亞","奈及利亞",
               "巴西","瑞士","哥斯大黎加","塞爾維亞",
               "德國","墨西哥","瑞典","南韓",
               "比利時","巴拿馬","突尼西亞","英格蘭",
               "波蘭","塞內加爾","哥倫比亞","日本")

###Korea Republic-->South Korea
EnglishName<-c("Russia","Saudi Arabia","Egypt","Uruguay",
               "Portugal","Spain","Morocco","Iran",
               "France","Australia","Peru","Denmark",
               "Argentina","Iceland","Croatia","Nigeria",
               "Brazil","Switzerland","Costa Rica","Serbia",
               "Germany","Mexico","Sweden","South Korea",
               "Belgium","Panama", "Tunisia","England",
               "Poland","Senegal","Colombia","Japan")
Group<-c("A","A","A","A",
         "B","B","B","B",
         "C","C","C","C",
         "D","D","D","D",
         "E","E","E","E",
         "F","F","F","F",
         "G","G","G","G",
         "H","H","H","H")
continent<-c("歐洲","亞洲","非洲","南美洲",
             "歐洲","歐洲","非洲","亞洲",
             "歐洲","亞洲","南美洲","歐洲",
             "南美洲","歐洲","歐洲","非洲",
             "南美洲","歐洲","中北美洲及加勒比海區","歐洲",
             "歐洲","中北美洲及加勒比海區","歐洲","亞洲",
             "歐洲","中北美洲及加勒比海區","非洲","歐洲",
             "歐洲","非洲","南美洲","亞洲")
###2017/10
worldranking<-c(65,63,30,17,
               3,8,48,34,
               7,43,10,19,
               4,21,18,41,
               2,11,22,38,
               1,16,25,62,
               5,49,28,12,
               6,32,13,44)

LotteryLevel<-c(1,4,3,2,
                1,2,4,3,
                1,4,2,3,
                1,3,2,4,
                1,2,3,4,
                1,2,3,4,
                1,4,3,2,
                1,3,2,4)
WorldCupGroup<-data.frame(
  中文名稱=ChineseName,
  英文名稱=EnglishName,
  組別=Group,
  洲別=continent,
  FIFA世界排名=worldranking,
  抽籤檔次=LotteryLevel)
write.csv(WorldCupGroup,file="C:/Users/Peter/Desktop/WorldCupGroup.csv",
          row.names = F,col.names = T,fileEncoding="UTF-8")
