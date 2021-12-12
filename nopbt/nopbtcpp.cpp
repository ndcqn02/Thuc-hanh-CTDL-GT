#include <stdio.h>
struct NUT{
	int dlieu;
	NUT *tiep;
};

NUT *BSUNG_S(NUT *D, NUT *ptu){
	NUT *tg;
	if(D==NULL)
		D=ptu;
	else{
		tg=D;	
		while(tg->tiep != NULL)
			tg = tg->tiep;
		tg->tiep = ptu;
	}
	return D;
}

void IN(NUT *D){
	NUT *tg=D;
	while(tg != NULL){
		printf("%d ",tg->dlieu);
		tg = tg->tiep;
	}
}

NUT *CHEN(NUT *D, *p){
	
}

main(){
	NUT *Dau, *p;
	int i,n;
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	Dau = NULL;
	for(i=1; i<=n; i++){
		p = new NUT;
		//p = (Node_List *)malloc(sizeof(Node_List));
		printf("Nhap so thu %d : ",i);
		scanf("%d",&p->dlieu);
		p->tiep =NULL;
		Dau = BSUNG_S(Dau, p);
	}
	IN(Dau);
	
	
	
	
}
