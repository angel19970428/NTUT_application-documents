import requests
from lxml import etree

URL="http://tslc.stats.com/liga/players.asp?player=21678"
res=requests.get(URL)


tree=etree.HTML(res.text)
#測試用
date=tree.xpath("//div[@id='shsFootball']/div[@id='shsIFBPlayer']/table[2]/tr/td[1]/a")[0].text
'''
print(date)
'''
trs=tree.xpath("//div[@id='shsFootball']/div[@id='shsIFBPlayer']/table[2]/tr")
trs_count=len(trs)
countt=0

f= open("Cristiano Ronaldo.csv","w")
f.write("2016-2017球季上場數據\n")
f.write("日期,對手,上場時間,進球,助攻,射正率,黃牌數\n")
for i in range(1,trs_count+1):
    countt=countt+1
    if countt<=1:
        continue
    if countt==31:
        continue
    date=tree.xpath("//div[@id='shsFootball']/div[@id='shsIFBPlayer']/table[2]/tr["+str(i)+"]/td[1]/a")[0].text
    opponent=tree.xpath("//div[@id='shsFootball']/div[@id='shsIFBPlayer']/table[2]/tr["+str(i)+"]/td[2]/a")[0].text
    mins=tree.xpath("//div[@id='shsFootball']/div[@id='shsIFBPlayer']/table[2]/tr["+str(i)+"]/td[3]")[0].text
    score=tree.xpath("//div[@id='shsFootball']/div[@id='shsIFBPlayer']/table[2]/tr["+str(i)+"]/td[4]")[0].text
    assists=tree.xpath("//div[@id='shsFootball']/div[@id='shsIFBPlayer']/table[2]/tr["+str(i)+"]/td[5]")[0].text
    shot_rate=tree.xpath("//div[@id='shsFootball']/div[@id='shsIFBPlayer']/table[2]/tr["+str(i)+"]/td[9]")[0].text
    yellow=tree.xpath("//div[@id='shsFootball']/div[@id='shsIFBPlayer']/table[2]/tr["+str(i)+"]/td[10]")[0].text
    print (str(date)+","+str(opponent)+","+str(mins)+","+str(score)+","+str(assists)+","+str(shot_rate)+"%,"+str(yellow))
    f.write(str(date)+","+str(opponent)+","+str(mins)+","+str(score)+","+str(assists)+","+str(shot_rate)+"%,"+str(yellow)+"\n")
f.close()



