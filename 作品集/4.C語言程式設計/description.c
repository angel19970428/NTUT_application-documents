#include <stdio.h>
#include <stdlib.h>


int description(){
	printf("1.輸入的年份只能從西元1年~西元9999年。\n");
	printf("2.本程式無法刪除，若想刪除記帳，只需在金額中輸入負值，即可抵銷。\n");
	printf("3.本程式無法刪除記事，所以請在確認輸入內容。\n");
	printf("4.行事曆只會顯示今天以後的事情。\n");
	printf("5.若在是否繼續記錄輸入否的話，則會在詢問一次是否離開程式。\n");
	printf("6.在看財務分析中，會先要求輸入年份，再要求輸入月份，請不要一次輸入年份月份。\n");
	printf("\n\n");
	system("PAUSE");
	return 0;
}
