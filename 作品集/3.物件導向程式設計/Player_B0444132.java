import java.util.ArrayList;

public class Player_B0444132 extends Player {
	public Player_B0444132(int chips){
		super("�i����(B0444132)",chips);
	}
	public int make_bet() {
		if(get_current_chips()>=10000){
			setBet(500);
			//���n�N�����u�U500(����3)
		}else if(get_current_chips()>=2000){
			setBet((get_current_chips()/4));
			//���w�X�j��2000�ɤ@���U1/4���w�X
			//win�ɷ|��5/4���w�X�Alose�ɷ|��3/4���w�X(����2)
		}else{
		setBet((get_current_chips()/3));
		//���w�X�p��2000�ɤ@���U1/3���w�X
		//win�ɷ|��4/3���w�X�Alose�ɷ|��2/3���w�X
		//���D�w�X�p��3�_�h���i�H�@���~��(����1)
		}
		//�S��B�z�w�X�p��3������
		if(get_current_chips()<3){setBet(1);}
		//���ҤU�`����j��{���w�X��
		if (getBet() <= get_current_chips()) {
			return getBet();
		} else {
			setBet(0);
			return getBet();
		}
	}
	public boolean hit_me(Table tbl) {
		int allCard=208;//52*4=208
		boolean winDealer=false;//�O�_Ĺ���a���P��(����4)
		int total_value = getTotalValue();
		Card dealerOpenCard= tbl.get_face_up_card_of_dealer();//���a½�}���P(����4)
		ArrayList<Card>openCard=new ArrayList<Card>();
    	openCard=tbl.getOpenedCards();//�ιL���P12~17(����5)
    	//�p��ѤU���P�̤j���h��12~15(����4)
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
    	if(total_value<=11){//1. 11�I�H�U�ҭn��
        	return true;
        }else if(total_value==12){//2. 12�I��
        	int danger=0;
        	double rate=danger/allCard;
        	//�p��M�I���P
        	for(Card c:openCard){
        		allCard--;
        		if(c.getRank()>=10){danger++;}
        	}
        	//��(���a½�}���P+�ѤU���P�̤j)��j�p
        	if((dealerOpenCard.getRank()+max)>12){winDealer=false;}
        	else{winDealer=true;}
        	//�M�w�O�_�n�P
        	if(winDealer==false){return true;}
        	else if(rate>0.5){return false;}
        	else{return true;}
        }else if(total_value==13){//3. 13�I��
        	int danger=0;
        	double rate=danger/allCard;
        	//�p��M�I���P
        	for(Card c:openCard){
        		allCard--;
        		if(c.getRank()>=9){danger++;}
        	}
        	//��(���a½�}���P+�ѤU���P�̤j)��j�p
        	if((dealerOpenCard.getRank()+max)>13){winDealer=false;}
        	else{winDealer=true;}
        	//�M�w�O�_�n�P
        	if(winDealer==false){return true;}
        	else if(rate>0.5){return false;}
        	else{return true;}
        }else if(total_value==14){//4. 14�I��
        	int danger=0;
        	double rate=danger/allCard;
        	//�p��M�I���P
        	for(Card c:openCard){
        		allCard--;
        		if(c.getRank()>=8){danger++;}
        	}
        	//��(���a½�}���P+�ѤU���P�̤j)��j�p
        	if((dealerOpenCard.getRank()+max)>14){winDealer=false;}
        	else{winDealer=true;}
        	//�M�w�O�_�n�P
        	if(winDealer==false){return true;}
        	else if(rate>0.5){return false;}
        	else{return true;}
        }else if(total_value==15){//5. 15�I��
        	int danger=0;
        	double rate=danger/allCard;
        	//�p��M�I���P
        	for(Card c:openCard){
        		allCard--;
        		if(c.getRank()>=7){danger++;}
        	}
        	//��(���a½�}���P+�ѤU���P�̤j)��j�p
        	if((dealerOpenCard.getRank()+max)>15){winDealer=false;}
        	else{winDealer=true;}
        	//�M�w�O�_�n�P
        	if(winDealer==false){return true;}
        	else if(rate<0.5){return true;}
        	else{return false;}
        }else if(total_value==16){//6. 16�I��
        	int danger=0;
        	double rate=danger/allCard;
        	//�p��M�I���P
        	for(Card c:openCard){
        		allCard--;
        		if(c.getRank()>=6){danger++;}
        	}
        	//�M�w�O�_�n�P
        	if(rate<0.5){return true;}
        	else{return false;}
        }else if(total_value==17){//7. 17�I��
        	int danger=0;
        	double rate=danger/allCard;
        	//�p��M�I���P
        	for(Card c:openCard){
        		allCard--;
        		if(c.getRank()>=5){danger++;}
        	}
        	//�M�w�O�_�n�P
            if(rate<0.5){return true;}
        	else{return false;}
        }else if(total_value>=18&&total_value<=21){//8. 18~21�I��(����6)
        	return false;
        }else{//9. �W�L21�I��
        	return false;
        }
		
	}
}
