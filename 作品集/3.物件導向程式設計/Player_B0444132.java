import java.util.ArrayList;

public class Player_B0444132 extends Player {
	public Player_B0444132(int chips){
		super("張仁樵(B0444132)",chips);
	}
	public int make_bet() {
		if(get_current_chips()>=10000){
			setBet(500);
			//見好就收都只下500(策略3)
		}else if(get_current_chips()>=2000){
			setBet((get_current_chips()/4));
			//當籌碼大於2000時一次下1/4的籌碼
			//win時會有5/4的籌碼，lose時會有3/4的籌碼(策略2)
		}else{
		setBet((get_current_chips()/3));
		//當籌碼小於2000時一次下1/3的籌碼
		//win時會有4/3的籌碼，lose時會有2/3的籌碼
		//除非籌碼小於3否則都可以一直繼續玩(策略1)
		}
		//特殊處理籌碼小於3的情形
		if(get_current_chips()<3){setBet(1);}
		//驗證下注不能大於現有籌碼值
		if (getBet() <= get_current_chips()) {
			return getBet();
		} else {
			setBet(0);
			return getBet();
		}
	}
	public boolean hit_me(Table tbl) {
		int allCard=208;//52*4=208
		boolean winDealer=false;//是否贏莊家的牌面(策略4)
		int total_value = getTotalValue();
		Card dealerOpenCard= tbl.get_face_up_card_of_dealer();//莊家翻開的牌(策略4)
		ArrayList<Card>openCard=new ArrayList<Card>();
    	openCard=tbl.getOpenedCards();//用過的牌12~17(策略5)
    	//計算剩下的牌最大為多少12~15(策略4)
    	int[]Rank=new int[12];
    	for(int i=0;i<=11;i++){Rank[i]=0;}
    	for(Card c:openCard){
    		for(int i=10;i>=2;i--){
    			if(c.getRank()==i){Rank[i]++;}
    		}
    		if(c.getRank()==1){Rank[11]++;}
    	}
    	int max=0;
    	if(Rank[11]<16){max=11;}
    	else if(Rank[10]<64){max=10;}
    	else{
    		for(int i=9;i>=2;i--){
    			if(Rank[i]<16){max=i;break;}
    		}
    	}
    	if(total_value<=11){//1. 11點以下皆要補
        	return true;
        }else if(total_value==12){//2. 12點時
        	int danger=0;
        	double rate=danger/allCard;
        	//計算危險的牌
        	for(Card c:openCard){
        		allCard--;
        		if(c.getRank()>=10){danger++;}
        	}
        	//跟(莊家翻開的牌+剩下的牌最大)比大小
        	if((dealerOpenCard.getRank()+max)>12){winDealer=false;}
        	else{winDealer=true;}
        	//決定是否要牌
        	if(winDealer==false){return true;}
        	else if(rate>0.5){return false;}
        	else{return true;}
        }else if(total_value==13){//3. 13點時
        	int danger=0;
        	double rate=danger/allCard;
        	//計算危險的牌
        	for(Card c:openCard){
        		allCard--;
        		if(c.getRank()>=9){danger++;}
        	}
        	//跟(莊家翻開的牌+剩下的牌最大)比大小
        	if((dealerOpenCard.getRank()+max)>13){winDealer=false;}
        	else{winDealer=true;}
        	//決定是否要牌
        	if(winDealer==false){return true;}
        	else if(rate>0.5){return false;}
        	else{return true;}
        }else if(total_value==14){//4. 14點時
        	int danger=0;
        	double rate=danger/allCard;
        	//計算危險的牌
        	for(Card c:openCard){
        		allCard--;
        		if(c.getRank()>=8){danger++;}
        	}
        	//跟(莊家翻開的牌+剩下的牌最大)比大小
        	if((dealerOpenCard.getRank()+max)>14){winDealer=false;}
        	else{winDealer=true;}
        	//決定是否要牌
        	if(winDealer==false){return true;}
        	else if(rate>0.5){return false;}
        	else{return true;}
        }else if(total_value==15){//5. 15點時
        	int danger=0;
        	double rate=danger/allCard;
        	//計算危險的牌
        	for(Card c:openCard){
        		allCard--;
        		if(c.getRank()>=7){danger++;}
        	}
        	//跟(莊家翻開的牌+剩下的牌最大)比大小
        	if((dealerOpenCard.getRank()+max)>15){winDealer=false;}
        	else{winDealer=true;}
        	//決定是否要牌
        	if(winDealer==false){return true;}
        	else if(rate<0.5){return true;}
        	else{return false;}
        }else if(total_value==16){//6. 16點時
        	int danger=0;
        	double rate=danger/allCard;
        	//計算危險的牌
        	for(Card c:openCard){
        		allCard--;
        		if(c.getRank()>=6){danger++;}
        	}
        	//決定是否要牌
        	if(rate<0.5){return true;}
        	else{return false;}
        }else if(total_value==17){//7. 17點時
        	int danger=0;
        	double rate=danger/allCard;
        	//計算危險的牌
        	for(Card c:openCard){
        		allCard--;
        		if(c.getRank()>=5){danger++;}
        	}
        	//決定是否要牌
            if(rate<0.5){return true;}
        	else{return false;}
        }else if(total_value>=18&&total_value<=21){//8. 18~21點時(策略6)
        	return false;
        }else{//9. 超過21點時
        	return false;
        }
		
	}
}
