#include<stdio.h>

// last in, fist out- chua sua
struct NL{
	int dl;
	NL *tiep;
};
NL *BOSUNG_S(NL *d, NL *ptu)
{
	NL *tg;
	if (d==NULL)
		d=ptu;
	else
	{
		ptu->tiep = d;
		d= ptu;	
	}
	return d;	
}
void INDS(NL *d)
{
		NL *tg;
		tg=d;
		while(tg!= NULL)
		{
		printf("%d ",tg->dl);
		tg= tg->tiep;
		}
}
void Nhap(NL *&d, int n)
{	
	NL *p;
	int i;
	for (i=1; i<=n; i++)
	{
		p=new NL;
		printf("Nhap phan tu thu %d:",i);
		scanf("%d",&p->dl);
		p->tiep = NULL;
		d=BOSUNG_S(d,p);
	}
}
//3.chen mot so vao day so  !!tang dan
NL *CHEN(NL *d, int x)
{
	NL *p, *tg, *trc;
	p = new NL;
	p->dl= x;
	p->tiep = NULL;
	tg=d;
	while (tg !=NULL && tg->dl < p->dl)  // chen giua
	{
		trc = tg;
		tg = tg->tiep;
	}
	
	// het vong while ma khong chen duoc so, thi chi co the la so nho nhat or lon nhat trong day
	if(tg == d)  // neu so chen la so nho nhat thì chèn vào dau
	{
		d = p;
		p->tiep = tg;
	}
	else		// nguoc lai: so chen lon hon tat ca, chen vao cuoi
	{
		trc->tiep = p;  // trc->tiep hien dang cuoi day va
		p->tiep = tg;
	}
	return d;
}

//6.kiem tra mot so co trong day so hay khong, tra ve vi tri
NL *TIMKIEM(NL *d, int x)
{
	NL *tg;
	tg = d;
	while (tg != NULL)
	{
		if (tg->dl == x)
			return tg;
		tg = tg->tiep;	
	}
	return NULL;
}

//4.xoa mot so co trong day so
NL *XOA(NL *d, int x)
{
	NL *tg, *trc;
	while(TIMKIEM(d, x)!=NULL)
	{
		tg =TIMKIEM(d, x); //lay vi tri so muon xoa
		if(tg==d)
			d=d->tiep;
		else
		{
			trc = d;
			while (trc->tiep !=tg)
				trc = trc->tiep;	// cho trc->tiep chay toi vi tri !!truoc so muon xoa
			trc->tiep = tg->tiep;	// xoa, lay tay cua truoc->tiep chi vao so sau so muon xoa,la tg->tiep
		}
		tg->tiep = NULL;	 // xoa dia chi ma so muon xoa luu tru
	}
	return d;
}


// 5.sap xep day tang dan
void sapXep(NL *d){
	NL *tg, *tg2,*trc;
	tg=d;
	tg2=d;
	int tam=0;
	for(tg; tg!=NULL; tg=tg->tiep){
		for(tg2=tg; tg2!=NULL; tg2=tg2->tiep ){
			if(tg->dl > tg2->dl){
				tam= tg->dl;
				tg->dl = tg2->dl;
				tg2->dl = tam;
			}
		}
	}
}

// noi2 day
NL *noi2Day(NL *&d, NL *d2 ){
	NL *tg;
	tg=d;
	while(tg->tiep !=NULL)
		tg=tg->tiep;
	tg->tiep = d2;
	sapXep(d);
	return d;
}

main()
{
	NL *h,*h2,*dnoi;
	int N,n2, so,sxoa;
	printf (" Nhap vao so luong ptu danh sach 1 :");
	scanf ("%d",&N);
	h=NULL;
	dnoi=NULL;
	Nhap(h, N);
	INDS(h);
	//sapxep
	sapXep(h);
	printf("\nDay sau khi sap xep tang: ");
	INDS(h);
	//chen
	printf("\nNhap vao so can chen : ");
	scanf("%d", &so);
	h =CHEN(h, so);
	INDS(h);
	//xoa	
	printf("\nNhap vao so can xoa : ");
	scanf("%d", &sxoa);
	h =XOA(h, sxoa);
	INDS(h);	
	//kiemtra
	printf("\nNhap vao so can tim : ");
	scanf("%d", &so);
	if(TIMKIEM(h, so)==NULL)
		printf("khong");
	else
		printf("co");		
	//ghepday
	printf("\nNhap so luong pt danh sach 2: ");
	scanf("%d",&n2);
	h2=NULL;
	Nhap(h2, n2);
	INDS(h2);	
	noi2Day(h, h2);
	printf("\n\n----Noi day da xoa voi day vua nhap");
	printf("\nNoi thanh day tang dan:  ");
	INDS(h);	
}
