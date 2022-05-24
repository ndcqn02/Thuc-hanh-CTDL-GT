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


// hàm tìm node th? m?ng
void NodeTheMang(NUT *&X, NUT *&Y) // NODE Y là node th? m?ng cho node c?n xóa - node này s? d?m nh?n nhi?m v? tìm ra node trái nh?t(TÌM NODE TRÁI NH?T CÂY CON PH?I) ho?c ph?i nh?t(TÌM NODE PH?I NH?T C?A CÂY CON TRÁI)
{
    // CÁCH 1: TÌM NODE TRÁI NH?T C?A CÂY CON PH?I
    // duy?t sang bên trái nh?t
    if (Y->L != NULL)
    {
        NodeTheMang(X, Y->L);// tìm ra node trái nh?t ?
    }
    else // tìm ra du?c node trái nh?t r?i nek..
    {
        X->ten = Y->ten; // c?p nh?t cái ten c?a node c?n xóa chính là ten c?a node th? m?ng
        X = Y; // cho node X(là node mà chúng ta s? di xóa sau này) tr? d?n node th? m?ng ==> ra kh?i hàm thì ta s? xóa node X
        Y = Y->R; // b?n ch?t ch? này chính là c?p nh?t l?i m?i liên k?t cho node cha c?a node th? m?ng(mà chúng ta s? xóa) v?i node con c?a node th? m?ng  
    }
 
    /* CÁCH 2: TÌM NODE PH?I NH?T C?A CÂY CON TRÁI
     duy?t sang bên ph?i
     if (Y->R != NULL)
    {
        DiTimNodeTheMang(X, Y->R);// tìm ra node ph?i nh?t ?
    }
    else // tìm ra du?c node ph?i nh?t r?i nek..
    {
        X->ten = Y->ten; // c?p nh?t cái ten c?a node c?n xóa chính là ten c?a node th? m?ng
        X = Y; // cho node X(là node mà chúng ta s? di xóa sau này) tr? d?n node th? m?ng ==> ra kh?i hàm thì ta s? xóa node X
        Y = Y->L; // b?n ch?t ch? này chính là c?p nh?t l?i m?i liên k?t cho node cha c?a node th? m?ng(mà chúng ta s? xóa) v?i node con c?a node th? m?ng   
    } */
}
 
// hàm xóa 1 cái node b?t kì trong cây nh? phân tìm ki?m
void XoaNode(NUT &t, char ten) // ten chính là giá tr? c?a cái node c?n xóa
{
    // n?u nhu cây dang r?ng
    if (t == NULL)
    {
        return; // k?t thúc hàm
    }
    else
    {
        // n?u nhu ten nh? hon node g?c
        if (ten < t->ten)
        {
            XoaNode(t->L, ten); // duy?t sang nhánh trái c?a cây 
        }
        else if (ten > t->ten)
        {
            XoaNode(t->R, ten); // duy?t sang nhánh ph?i c?a cây 
        }
        else // ten == t->ten - dã tìm ra cái node c?n xóa
        {
            NODE *X = t; // node X là node th? m?ng - tí n?a chúng ta s? xóa nó
            // n?u nhu nhánh trái b?ng NULL <=> dây là cây có 1 con chính là con ph?i
            if (t->L == NULL)
            {
                // duy?t sang ph?i c?a cái node c?n xóa d? c?p nh?t m?i liên k?t gi?a node 
                // cha c?a node c?n xóa v?i node con c?a node c?n xóa
                t = t->R; 
            }
            else if (t->R == NULL)
            {
                // duy?t sang trái c?a cái node c?n xóa d? c?p nh?t m?i liên k?t gi?a node 
                // cha c?a node c?n xóa v?i node con c?a node c?n xóa
                t = t->L;
            }
            else // node c?n xóa là node có 2 con
            {
                // CÁCH 1: Tìm node trái nh?t c?a cây con ph?i(cây con ph?i c?a cái node c?n xóa)
                NodeTheMang(X, t->R);
                // CÁCH 2: Tìm node ph?i nh?t c?a cây con trái(cây con trái c?a cái node c?n xóa)
                //DiTimNodeTheMang(X, t->L);
            }
            delete X; // xóa node c?n xóa
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


	

