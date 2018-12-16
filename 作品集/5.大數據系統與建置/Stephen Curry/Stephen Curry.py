import requests
from lxml import etree

URL="http://tslc.stats.com/nba/playerstats.asp?id=4612&team=9&page=logs"
res=requests.get(URL)
#不需要的tr
list1=[10,11,12,28,29,30,47,48,49,63,64,65,66,79,80,81,87,98,99,100,104,111,112,113,122,123,124,130]
list_count=len(list1)
#檢查if用的
status=0

tree=etree.HTML(res.text)
date=tree.xpath("//table[@class='shsTable shsBorderTable']/tr[8]/td[2]")[0].text

trs=tree.xpath("//table[@class='shsTable shsBorderTable']/tr")
trs_count=len(trs)
#測試用
'''
print(date)
'''
f=open("Stephen Curry.csv","w")
f.write("2016-2017球季上場數據\n")
f.write("日期,對手,結果,上場時間,得分,籃板,助攻,抄截,火鍋,失誤,犯規,雙十,大三元,命中率,三分球命中率\n")
for i in range(7,trs_count+1):
    status=0
    for j in range(0,list_count):
        if (i==list1[j])and(status==0):
            status=1        
    if status==0:    
        #處理日期格式
        date=tree.xpath("//table[@class='shsTable shsBorderTable']/tr["+str(i)+"]/td[1]")[0].text
        month=date[3:]
        day=date[0:2]
        date=month+"/"+day
        opponent=tree.xpath("//table[@class='shsTable shsBorderTable']/tr["+str(i)+"]/td[2]")[0].text
        #處理不同的xpath
        if opponent is None:
            opponent=tree.xpath("//table[@class='shsTable shsBorderTable']/tr["+str(i)+"]/td[2]/a")[0].text
        else: 
            opponent+=tree.xpath("//table[@class='shsTable shsBorderTable']/tr["+str(i)+"]/td[2]/a")[0].text
        result=tree.xpath("//table[@class='shsTable shsBorderTable']/tr["+str(i)+"]/td[3]/span")[0].text
        result+=tree.xpath("//table[@class='shsTable shsBorderTable']/tr["+str(i)+"]/td[3]/a")[0].text
        mins=tree.xpath("//table[@class='shsTable shsBorderTable']/tr["+str(i)+"]/td[4]")[0].text
        score=tree.xpath("//table[@class='shsTable shsBorderTable']/tr["+str(i)+"]/td[17]")[0].text
        rebound=tree.xpath("//table[@class='shsTable shsBorderTable']/tr["+str(i)+"]/td[15]")[0].text
        assist=tree.xpath("//table[@class='shsTable shsBorderTable']/tr["+str(i)+"]/td[16]")[0].text
        steal=tree.xpath("//table[@class='shsTable shsBorderTable']/tr["+str(i)+"]/td[11]")[0].text
        block=tree.xpath("//table[@class='shsTable shsBorderTable']/tr["+str(i)+"]/td[12]")[0].text
        turnover=tree.xpath("//table[@class='shsTable shsBorderTable']/tr["+str(i)+"]/td[13]")[0].text
        foul=tree.xpath("//table[@class='shsTable shsBorderTable']/tr["+str(i)+"]/td[14]")[0].text
        if((int (score)>=10)and(int(assist)>=10))or((int(score)>=10)and(int(rebound)>=10))or(int(rebound)>=10)and(int(assist)>=10):
            double="是"
        else:
            double="否"
        if(int(score)>=10)and(int(rebound)>=10)and(int(assist)>=10):
            big3="是"
        else:
            big3="否"
        shot_rate=tree.xpath("//table[@class='shsTable shsBorderTable']/tr["+str(i)+"]/td[6]")[0].text
        shot3_rate=tree.xpath("//table[@class='shsTable shsBorderTable']/tr["+str(i)+"]/td[8]")[0].text
        print(date+","+opponent+","+result+","+mins+","+score+","+rebound+","+assist+","+steal+","+block+","+turnover+","+foul+","+double+","+big3+",0"+shot_rate+",0"+shot3_rate)
        f.write(date+","+opponent+","+result+","+mins+","+score+","+rebound+","+assist+","+steal+","+block+","+turnover+","+foul+","+double+","+big3+",0"+shot_rate+",0"+shot3_rate+"\n")
f.close()
        


