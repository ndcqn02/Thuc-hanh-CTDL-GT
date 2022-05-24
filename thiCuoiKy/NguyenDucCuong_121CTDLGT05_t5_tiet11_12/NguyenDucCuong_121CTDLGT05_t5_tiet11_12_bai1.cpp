#include <stdio.h>
#include <string.h>
struct SINHVIEN
{
    char msv[50], ten[50];
    float diemcc, diemgk, diemck, dtb;
};

struct NUT
{
    SINHVIEN dl;
    NUT *tiep;
};

NUT *BSung(NUT *D, NUT *ptu)
{
    NUT *tg;
    if (D == NULL)
    {
        D = ptu;
    }
    else
    {
        tg = D;
        while (tg->tiep != NULL)
        {
            tg = tg->tiep;
        }
        tg->tiep = ptu;
    }
    return D;
}

void NHAP(NUT *&D)
{
    NUT *p;
    int n;
    printf("so sinh vien muon nhap : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        p = new NUT;
        printf("Nhap ma sv %d: ", i);
        fflush(stdin);
        gets(p->dl.msv);
        printf("Nhap ten : ");
        gets(p->dl.ten);
        printf("Nhap diem chuyen can : ");
        scanf("%f", &p->dl.diemcc);
        printf("Nhap diem giua ky : ");
        scanf("%f", &p->dl.diemgk);
        printf("Nhap diem cuoi ky : ");
        scanf("%f", &p->dl.diemck);
        p->tiep = NULL;
        D = BSung(D, p);
    }
}


NUT *THEM(NUT *D, NUT *ptu, int vt)
{   
    NUT * tg;
    tg = D;
    int i = 1;
	if(vt == 0 || D == NULL){
		if(D == NULL){
       	 	D = ptu; 
	    }else{
	        ptu->tiep = D; 
	        D = ptu;
    	}
	}
	else{
		while(tg != NULL && i != vt){
            tg = tg->tiep;
            ++i;
        }
	    if (i < vt)
	    {
	        D = BSung(D,ptu);
	    }
	    else
	    {	 
	        ptu->tiep = tg->tiep;
	        tg->tiep = ptu;
	    }  	
	}
    return D;
}

void Duyet(NUT *D)
{
    printf("%10s | %20s | %7s | %7s | %7s | %7s\n", "MA SV", "TEN SV", "DIEM CC", "DIEM GK", "DIEM CK", "DTB");
    while (D != NULL)
    {
        printf("%10s | %20s | %7.2f | %7.2f | %7.2f | %7.2f\n", D->dl.msv, D->dl.ten, D->dl.diemcc, D->dl.diemgk, D->dl.diemck, D->dl.dtb);
        D = D->tiep;
    }
}


NUT *TIMKIEM(NUT *D, char tim[50])
{
    NUT *tg;
    tg = D;
    while (tg != NULL)
    {
        if (strcmp(tg->dl.msv, tim) == 0)
        {
            return tg;
        }
        tg = tg->tiep;
    }
    return NULL;
}

NUT *XOA(NUT *&D, char code[50])
{
    NUT *tg, *trc, *t;
    while(TIMKIEM(D, code) != NULL) 
    {
        tg = TIMKIEM(D, code);
        if (tg == D){
            D = D->tiep;
        }
        else
        {
            trc = D;
            while (trc->tiep != tg)
            {
                trc = trc->tiep;
            }
            trc->tiep = tg->tiep;
        }
        tg->tiep = NULL;
    }
    return D;
}


void tinhDTB(NUT *D)
{
    NUT *tg;
    tg = D;

    while (tg != NULL)
    {
        tg->dl.dtb = (tg->dl.diemcc * 0.2 + tg->dl.diemgk * 0.2 + tg->dl.diemck * 0.6);
        tg = tg->tiep;
    }
}

NUT *vtriDTB(NUT *D)
{
    NUT *tmp, *tg;
    tg = D;
    float max = tg->dl.dtb;
    while (tg != NULL)
    {
        if (tg->dl.dtb > max)
        {
            max = tg->dl.dtb;
            tmp = tg;
        }
        tg = tg->tiep;
    }
    if (max == D->dl.dtb)
        return D;
    else
        return tmp;
}

int ViTri(NUT *D){
    int count = 1;
    NUT * tg,*vt;
    tg = D;
    vt = vtriDTB(D);
    while (tg->dl.dtb != vt->dl.dtb )
    {
        count++;
        tg = tg->tiep;
    }
    return count;
}

// 4.sap xep theo msv
void sxMaSV(NUT *D)
{
    NUT *tg, *tg2;
    SINHVIEN tmp;
    tg = D;
    tg2 = D;
    for (tg; tg != NULL; tg = tg->tiep)
    {
        for (tg2 = tg->tiep; tg2 != NULL; tg2 = tg2->tiep)
        {
            if (strcmp(tg2->dl.msv, tg->dl.msv) == 1)
            {
                tmp = tg->dl;
                tg->dl = tg2->dl;
                tg2->dl = tmp;
            }
        }
    }
}

// 5. sap xep ds theo dtb
void sxDTB(NUT *D)
{
    NUT *tg, *tg2;
    SINHVIEN tmp;
    tg = D;
    tg2 = D;
    for (tg; tg != NULL; tg = tg->tiep)
    {
        for (tg2 = tg->tiep; tg2 != NULL; tg2 = tg2->tiep)
        {
            if (tg2->dl.dtb < tg->dl.dtb)
            {
                tmp = tg->dl;
                tg->dl = tg2->dl;
                tg2->dl = tmp;
            }
        }
    }
}



int main()
{
    NUT *H, *vt, *p;
    char xoa[50],timkiem[50];
    H = NULL;
    int choose, vtthem;
    do
    {
        printf("\n---------------- MENU ------------------\n");
        printf("1.NHAP DANH SACH \n");
        printf("2.THEM \n");
        printf("3.TIM KIEM THEO MA SINH VIEN \n");
        printf("4.XOA \n");
        printf("5.DUYET \n");
        printf("6.TINH DIEM TRUNG BINH\n");
        printf("7.TIM VI TRI CUA NODE CO DTB CAO NHAT \n");
        printf("8.TIM KIEM SINH VIEN CO DIEM TRUNG BINH CAO NHAT \n");
        printf("9.SAP XEP THEO MA SINH VIEN\n");
        printf("10.SAP XEP THEO DIEM TRUNG BINH \n");
        printf("0.THOAT");
        printf("\n---------------------------------------\n");
        printf("Moi ban chon: ");
        scanf("%d",&choose);
        switch (choose)
        {
            case 1:
            {
                NHAP(H);
                tinhDTB(H);
                Duyet(H);
            }
                break;
            case 2:
            {
            	p = new NUT;
            	fflush(stdin);
            	printf("Nhap vi tri muon them : ");
                scanf("%d",&vtthem);
                fflush(stdin);
                printf("Nhap ma sinh vien muon them: ");
                gets(p->dl.msv);
                printf("Nhap ten : ");
                gets(p->dl.ten);
                printf("Nhap diem chuyen can : ");
                scanf("%f", &p->dl.diemcc);
                printf("Nhap diem giua ky : ");
                scanf("%f", &p->dl.diemgk);
                printf("Nhap diem cuoi ky : ");
                scanf("%f", &p->dl.diemck);
                p->tiep = NULL;
                THEM(H, p,vtthem);
                tinhDTB(H);
                Duyet(H);
            }
            break;
            case 3:
            {
                printf("Nhap ma sinh vien muon tim kiem: ");
                fflush(stdin);
                scanf("%s", &timkiem);
                fflush(stdin);
                if (TIMKIEM(H, timkiem) != NULL)
                {
                    printf("\nCo sinh vien nay trong danh sach \n");
                }
                else 
                {
                     printf("\nKhong co sinh vien nay trong danh sach\n");
                }
            }
                break;
            case 4:
            {
            	printf("Nhap ma sinh vien muon xoa: ");
                fflush(stdin);
                scanf("%s", &xoa);
                XOA(H, xoa);
                fflush(stdin);
            }
                break;
            case 5:
            {
                Duyet(H);
            }
            break;
            case 6:
            	tinhDTB(H);
                Duyet(H);
                break;
            case 7:
            {
            	printf("Vi tri cua sinh vien co diem trung binh cao nhat la: %d",ViTri(H));
            }
            break;
            case 8:
            {
                vt = vtriDTB(H);
                printf(" \nSinh vien co dtb max : \n ");
                printf("%10s | %20s | %7.2f | %7.2f | %7.2f | %7.2f\n", vt->dl.msv, vt->dl.ten, vt->dl.diemcc, vt->dl.diemgk, vt->dl.diemck, vt->dl.dtb);
            }
            break;
            case 9:
            {
                sxMaSV(H);
                printf("SAU KHI SAP XEP THEO MA SV :\n");
                Duyet(H);
            }
            break;
            case 10:
            {
                sxDTB(H);
                printf("SAU KHI SAP XEP THEO DTB : \n");
                Duyet(H);
            }
            break;
            default:
                printf(" MOI CHON LAI!!!");
                break;
            }
    } while (choose != 0);
}
