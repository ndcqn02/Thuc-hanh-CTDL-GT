#include <stdio.h>
#include <string.h>
struct NUT{
	char ten[50];
	NUT *L,*R;
};

NUT *BSung(NUT *cay, NUT *ptu){
	NUT *tg, *trc;
	if(cay == NULL)
		cay = ptu;
	else{
		tg = cay;
		while(tg!= NULL){
			trc = tg;
			if(strcmp(tg->ten,ptu->ten) > 0)
				tg = tg->L;
			else
				tg= tg->R;
		}
		if(strcmp(trc->ten, ptu->ten) > 0)
			trc->L = ptu;
		else
			trc->R = ptu;
	}
	return cay;
}

void inCay(NUT *cay){
	if(cay != NULL){
		printf("%s \n",cay->ten);
		inCay(cay->L);
		inCay(cay->R);
	}
}

void inCay_S(NUT *cay){
	if(cay != NULL){
		inCay_S(cay->L);
		inCay_S(cay->R);
		printf("%s \n",cay->ten);
	}
}


void inCay_view(NUT *cay){
	if(cay != NULL){
		inCay_view(cay->L);
		printf("%s \n",cay->ten);
		inCay_view(cay->R);
	}
}


int DemSV(NUT *cay){
	if (cay == NULL)
		return 0;
	else
		return 1 + DemSV(cay->L) + DemSV(cay->R);
}

int DemTENSV(NUT *cay, char dten[]){
	if (cay == NULL)
		return 0;
	if(strcmp(cay->ten,dten) == 0)
		return 1 + DemTENSV(cay->L, dten) + DemTENSV(cay->R,dten);
	else
		if(strcmp(cay->ten,dten) < 0)
			return DemTENSV(cay->R,dten);
	return  DemTENSV(cay->L, dten);
}


NUT *SEARCH_Tr_2 (NUT *cay, char x[]){
	NUT *tg;
    tg = cay;
    while (tg!=NULL && strcmp(tg->ten, x)!=0)
        if (strcmp(tg->ten,x) > 0)
            tg = tg->L; 
        else
            tg = tg->R; 
    if (tg!=NULL)
        return tg;
    else
        return NULL;
}


// start delete
	NUT *DELETE_Node(NUT *Tr, char info[])
	{
		NUT *tmp, *R, *t, *L;
		while (SEARCH_Tr_2(Tr, info)!=NULL)
		{
			tmp= SEARCH_Tr_2(Tr, info);
			if (tmp == Tr)  // xoa goc
			{
				if (tmp->L !=NULL )
				{
					R = Tr->R;
					Tr = Tr->L;
					tmp->L=NULL;
					tmp->R=NULL;
					tmp = Tr;
					while (tmp->R !=NULL)
						tmp = tmp->R;
					tmp->R = R;
				}
				else
				{
					Tr = Tr->R;
					tmp->R=NULL;
				}
			}
		else
		{
			t = Tr;
			while (t->R!=tmp && t->L!=tmp)
				if (t->ten >info )
					t = t->L;
				else
					t = t->R;
			if (tmp->L== NULL && 	tmp->R==NULL)
				if (t->R==tmp)
					t->R = NULL;
				else
					t->L = NULL;
			else
				if (tmp->L== NULL)
				{
					R = tmp->R;
					if (t->L== tmp)
						t->L = R;
					else
						t->R = R;
					tmp->R = NULL;
				}
				else
					if (tmp->R== NULL)
					{
						L = tmp->L;
						if (t->L== tmp)
							t->L = L;
						else
						t->R = L;
						tmp->L = NULL;
					}
					else
					{
						if (t->L== tmp)
						{
							t->L = tmp->L;
							t = t->L;
						}
						else
						{
							t->R = tmp->L;
							t = t->R;
						}
						while (t->R!=NULL)
							t = t->R;
						t->R = tmp->R;
						tmp->R=NULL;
						tmp->L=NULL;
					}	
		}
	}
	return Tr;
	}


// h�m t�m node th? m?ng
void NodeTheMang(NUT *&X, NUT *&Y) // NODE Y l� node th? m?ng cho node c?n x�a - node n�y s? d?m nh?n nhi?m v? t�m ra node tr�i nh?t(T�M NODE TR�I NH?T C�Y CON PH?I) ho?c ph?i nh?t(T�M NODE PH?I NH?T C?A C�Y CON TR�I)
{
    // C�CH 1: T�M NODE TR�I NH?T C?A C�Y CON PH?I
    // duy?t sang b�n tr�i nh?t
    if (Y->L != NULL)
    {
        NodeTheMang(X, Y->L);// t�m ra node tr�i nh?t ?
    }
    else // t�m ra du?c node tr�i nh?t r?i nek..
    {
        X->ten = Y->ten; // c?p nh?t c�i ten c?a node c?n x�a ch�nh l� ten c?a node th? m?ng
        X = Y; // cho node X(l� node m� ch�ng ta s? di x�a sau n�y) tr? d?n node th? m?ng ==> ra kh?i h�m th� ta s? x�a node X
        Y = Y->R; // b?n ch?t ch? n�y ch�nh l� c?p nh?t l?i m?i li�n k?t cho node cha c?a node th? m?ng(m� ch�ng ta s? x�a) v?i node con c?a node th? m?ng  
    }
 
    /* C�CH 2: T�M NODE PH?I NH?T C?A C�Y CON TR�I
     duy?t sang b�n ph?i
     if (Y->R != NULL)
    {
        DiTimNodeTheMang(X, Y->R);// t�m ra node ph?i nh?t ?
    }
    else // t�m ra du?c node ph?i nh?t r?i nek..
    {
        X->ten = Y->ten; // c?p nh?t c�i ten c?a node c?n x�a ch�nh l� ten c?a node th? m?ng
        X = Y; // cho node X(l� node m� ch�ng ta s? di x�a sau n�y) tr? d?n node th? m?ng ==> ra kh?i h�m th� ta s? x�a node X
        Y = Y->L; // b?n ch?t ch? n�y ch�nh l� c?p nh?t l?i m?i li�n k?t cho node cha c?a node th? m?ng(m� ch�ng ta s? x�a) v?i node con c?a node th? m?ng   
    } */
}
 
// h�m x�a 1 c�i node b?t k� trong c�y nh? ph�n t�m ki?m
void XoaNode(NUT &t, char ten) // ten ch�nh l� gi� tr? c?a c�i node c?n x�a
{
    // n?u nhu c�y dang r?ng
    if (t == NULL)
    {
        return; // k?t th�c h�m
    }
    else
    {
        // n?u nhu ten nh? hon node g?c
        if (ten < t->ten)
        {
            XoaNode(t->L, ten); // duy?t sang nh�nh tr�i c?a c�y 
        }
        else if (ten > t->ten)
        {
            XoaNode(t->R, ten); // duy?t sang nh�nh ph?i c?a c�y 
        }
        else // ten == t->ten - d� t�m ra c�i node c?n x�a
        {
            NODE *X = t; // node X l� node th? m?ng - t� n?a ch�ng ta s? x�a n�
            // n?u nhu nh�nh tr�i b?ng NULL <=> d�y l� c�y c� 1 con ch�nh l� con ph?i
            if (t->L == NULL)
            {
                // duy?t sang ph?i c?a c�i node c?n x�a d? c?p nh?t m?i li�n k?t gi?a node 
                // cha c?a node c?n x�a v?i node con c?a node c?n x�a
                t = t->R; 
            }
            else if (t->R == NULL)
            {
                // duy?t sang tr�i c?a c�i node c?n x�a d? c?p nh?t m?i li�n k?t gi?a node 
                // cha c?a node c?n x�a v?i node con c?a node c?n x�a
                t = t->L;
            }
            else // node c?n x�a l� node c� 2 con
            {
                // C�CH 1: T�m node tr�i nh?t c?a c�y con ph?i(c�y con ph?i c?a c�i node c?n x�a)
                NodeTheMang(X, t->R);
                // C�CH 2: T�m node ph?i nh?t c?a c�y con tr�i(c�y con tr�i c?a c�i node c?n x�a)
                //DiTimNodeTheMang(X, t->L);
            }
            delete X; // x�a node c?n x�a
        }
    }
}



// the end delete
main(){
	NUT *tree, *p;
	int n;
	char xoa[50];
	tree = new NUT;
	tree = NULL;
	printf("Nhap bao nhieu sinh vien: ");
	scanf("%d",&n);
	fflush(stdin) ;
	for(int i=1; i<=n; i++){
		p = new NUT;
		printf("Nhap sv thu %d: ",i);
		gets(p->ten);
		p->R = NULL;
		p->L = NULL;
		tree = BSung(tree, p);
	}
	
//	inCay(tree);
//	printf(" \n in sau \n");
	inCay_S(tree);
	printf("So node co trong cay la : %d",DemSV(tree));
	printf("\nSo node co trong cay trung voi ten la : %d",DemTENSV(tree, "cuong"));
	
	printf("\nNhap ten muon xoa : ");
	fflush(stdin) ;
	scanf("%s",&xoa);
	DELETE_Node(tree, xoa);
	inCay_S(tree);
}


	

