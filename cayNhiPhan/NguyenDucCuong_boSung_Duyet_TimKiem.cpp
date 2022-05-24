#include <stdio.h>
struct NUT{
    int dl;
    NUT *R, *L;
 };
 
NUT *BSUNG (NUT *cay, NUT *ptu){
    NUT *tg, *trc;
    if (cay == NULL)
        cay = ptu;
    else{
    	tg = cay;
        while (tg != NULL){
        	trc = tg;
            if (tg->dl > ptu->dl)
                tg = tg->L;
            else
                tg = tg->R;
		}           
        if (trc->dl > ptu->dl)
            trc->L = ptu;
        else
            trc->R = ptu;
	}
    return cay;
}

void INCAY_TGP (NUT *cay){
	if (cay != NULL){	
        INCAY_TGP (cay->L) ;
        printf("%d ", cay->dl);
        INCAY_TGP (cay->R);
	}     
}

void INCAY_GTP (NUT *cay){
	if (cay != NULL){
		printf("%d ", cay->dl);
        INCAY_GTP (cay->L) ;
        INCAY_GTP (cay->R);
	}     
}

void INCAY_TPG (NUT *cay){
	if (cay != NULL){
        INCAY_TPG (cay->L);
        INCAY_TPG (cay->R);
        printf("%d ", cay->dl);
	}     
} 

void INCAY_PGT (NUT *cay){ // pgt
	if (cay != NULL){
        INCAY_PGT (cay->R);
        printf("%d ", cay->dl);
        INCAY_PGT (cay->L);
	}     
} 

void INCAY_PTG (NUT *cay){ // ptg
	if (cay != NULL){
        INCAY_PTG (cay->R);
        INCAY_PTG (cay->L);
        printf("%d ", cay->dl);
        
	}     
}
void INCAY_GPT (NUT *cay){ // gpt
	if (cay != NULL){
		printf("%d ", cay->dl);
        INCAY_GPT (cay->R);
        INCAY_GPT (cay->L);
        
        
	}     
} 







NUT *TKIEM (NUT *cay, int x){
	NUT *tg;
    tg = cay;
    while (tg!=NULL && tg->dl!=x)
        if (tg->dl > x)
            tg = tg->L; 
        else
            tg = tg->R; 
    if (tg!=NULL)
        return tg;
    else
        return NULL;
}


NUT *CHEN(NUT *cay, NUT *ptu){
	NUT *tg;
	tg = cay;
	tg = BSUNG ( tg, ptu);
	return cay;
}

//NUT *XOA(NUT *cay, int x){ // xoa o goc
//	NUT *tg, *t, *R_cg;
//	tg = TKIEM(cay, x);
//	if (tg == cay)
//	{
//	   cay = tg->L;
//	   tg->L = NULL;
//	   t = cay;
//	   while (t!=NULL){
//	       R_cg = t;
//	       t = t->R;
//	    }
//	   R_cg->R = tg->R;
//	   tg->R = NULL;
//	}
//	return cay;
//}


NUT *XOA(NUT *cay, int x)
{
	NUT *tk, *tgL, *tgR, *tg, *c;
	//tk= TKIEM(cay, x);
	while (TKIEM(cay, x)!=NULL)
	{
		tk= TKIEM(cay, x);
		if (tk ==cay) // goc
		{
			if (cay->R!=NULL)
			{
				cay = cay->R;
				tg = cay;
				while (tg!=NULL)
				{
					tgL=tg;
					tg = tg->L;
				}	
				tgL->L = tk->L	;
				tk->L = NULL;			
			}
			else
				if (cay->L!=NULL) 
				{
					cay = cay->L;
					tk->L = NULL;
				}
				else
					cay = NULL;												
		}
		else
		{
			if (tk->R==NULL && tk->L==NULL)//la
			{
				tg = cay;
				while (tg->L != tk && tg->R!=tk )
					if (tg->dl > x)
						tg = tg->L;
					else
						tg = tg ->R;
				if (tg->L ==tk)
					tg->L=NULL;	
				else	
					tg->R=NULL;			
			}
			else
				if (tk->R!=NULL && tk->L!=NULL) // cay du
				{
					c = cay;
					while (c->L != tk && c->R!=tk )
					if (c->dl > x)
						c = c->L;
					else
						c = c ->R;
					if (c->R !=NULL)
					{
						c->R = tk->R;	
						tk->R= NULL;
						tg = c->R;
						while (tg!=NULL)
						{
							tgL = tg;
							tg = tg->L;
						}	
						tgL->L = tk->L;
						tk->L =NULL;
					}
					else{
					c->L = tk->R;
					tg = c->L; }
					while (tg!=NULL)
					{
						tgL= tg;
						tg = tg->L;
					}	
					tgL->L = tk->L;
					tk->L = NULL;					
				}
				////// xoa
				else{ // cay lech trai phai
					if(tk->R!=NULL && tk->L == NULL){
						c = cay;
						while (c->L !=tk && c->R!=tk )
						if (c->dl > x)
							c = c->L;
						else
							c = c ->R;
							
						if(c->R !=NULL && tk->R!=NULL){ // lech phai hoan toan
							c->R = tk->R;
							tk->R = NULL;
						}
						if(c->L !=NULL && tk->R!=NULL){// trai het cuoi phai
							c->L = tk->R;
							tk->R = NULL;
						}
					
					}
					if(tk->R==NULL && tk->L != NULL){// cay lech trai
						c = cay;
						while (c->L !=tk && c->R!=tk )
						if (c->dl > x)
							c = c->L;
						else
							c = c ->R;
							
						if(c->L !=NULL && tk->L!=NULL){	 // lech trai hoan toan
							c->L = tk->L;
							tk->L = NULL;
						}
						if(c->R !=NULL && tk->L!=NULL){ // lech phai het, cuoi trai
							c->R = tk->L;
							tk->L = NULL;
						}
								
					}
				}	
		}		
	}
	return cay;
}
main(){
	NUT *Tree, *p,*chen;
	int n, i, so,xoa;
	Tree = NULL;
	printf("Nhap bao nhieu so: ");
	scanf ("%d", &n);
	for (i=1;i<=n;i++){
	    p = new NUT;
	    printf("Nhap so thu %d: ", i);
	    scanf("%d", &p->dl);
	    p->R = NULL;
	    p->L = NULL;
	    Tree = BSUNG (Tree, p);
	}
	printf(" Duyet (TGP) : ");
	INCAY_TGP(Tree);	
	printf("\n Duyet  (GTP) ");
	INCAY_GTP(Tree);
	printf("\n Duyet  (TPG) ");
	INCAY_TPG(Tree);
	
	printf("\n phai  \n");
	printf("\n Duyet  (PTG) ");
	INCAY_PTG(Tree);
	printf("\n Duyet  (PGT) ");
	INCAY_PGT(Tree);
	printf("\n Duyet  (GPT) ");
	INCAY_GPT(Tree);
	

	printf("\n Nhap so tim: ");
	scanf ("%d", &so);	
	if(TKIEM (Tree, so) != NULL)
		printf(" Co");
	else
		printf(" Khong");
	
//	chen = new NUT;
//	printf("\n nhap so can chen: ");
//	scanf("%d", &chen->dl);
//	chen->L = NULL;
//	chen->R = NULL;
//	CHEN(Tree, chen);
//	printf(" Duyet (TGP) : ");
//	INCAY_TGP(Tree);
	
	printf("\nNhap so can xoa: ");
	scanf("%d", &xoa);
	Tree = XOA(Tree, xoa);
	printf("Day so da xoa: \n");
	INCAY_TGP(Tree);


}
	
	
	
	




