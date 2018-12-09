#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using std::string;
int unknown_d1; char arch[64]; int lArch; int nChips; int keyIdx = 0;
bool xxxflag = false;
struct Arch{
	char name[256];
	int a,b,c,d,pfb,bram,dsps,h,pads,j;
	// 32 36 40 44 48 52 56 60 64 72
	int k,l,m,n;
	// 238 400 482 564

	// +64 == pads????
} archs[10];


char buf0[256], buf1[256], buf2[256], buf3[256];

void debug(FILE *f){

	fgets(buf0, 256,f);
	printf(buf0);
	fgets(buf0, 256,f);
	printf(buf0);
	fgets(buf0, 256,f);
	printf(buf0);
	fclose(f);
	exit(0);
}

int decode(char *org, char*rst){
	int n = strlen(org);
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (org[i] == '!') {
			rst[j++] = org[++i];
		} else {
			int t = (int)org[i] - (int)arch[keyIdx];
			if (t <= 33)
				t += 93;
			rst[j++] = t;
		}
		keyIdx++;
		keyIdx %= lArch;
	}
	rst[j++] = '\0';
	return strlen(rst);
}

int ri(FILE* f){
	int x; fscanf(f, "%d", &x);
	printf("%d ", x);
	return x;
}

void sub_2060230(FILE *f){
	int flag1, n11,n12,n13,n14,n15,n16,n17;
	fscanf(f, "%d %d %d %d %d %d %d %d", &flag1, &n11, &n12, &n13,
	 &n14, &n15, &n16, &n17);
	printf( "%d %d %d %d %d %d %d %d ", flag1, n11, n12, n13, n14, n15, n16, n17);
	for (int i = 0; i < n11; i++) 
		ri(f); //pushback
	for (int i = 0; i < n12; i++)
		ri(f); //pushback
	for (int i = 0; i < n13; i++)
		ri(f); //pushback
	for (int i = 0; i < n14; i++)
		ri(f); //pushback
	for (int i = 0; i < n15; i++) {
		int a1,a2,a3,a4;
		fscanf(f, "%d %d %d %d", &a1, &a2, &a3, &a4); //164
		printf("%d %d %d %d ", a1,a2,a3,a4);
	}
	for (int i = 0; i < n16; i++)
		ri(f); //pushback
	for (int i = 0; i < n17; i++) {
		int a1,a2,a3,a4;
		fscanf(f, "%d %d %d %d", &a1, &a2, &a3, &a4); //241
		printf("%d %d %d %d ", a1,a2,a3,a4);
	}
	puts("");
	fscanf(f, "\n");
}
void sub_20619D0(FILE *f){
	int n1, n2, n3;
	fscanf(f, "%d %d %d\n", &n1, &n2, &n3);
	printf("%d %d %d\n", n1,n2,n3);
	for (int i = 0; i < n1; i++) {
		int x1;
		fscanf(f, "%s %d\n", buf0, &x1);
		decode(buf0, buf3);
		printf("%s %d\n", buf3, x1);
	}
	for (int i = 0; i < n2; i++) {
		int x1;
		fscanf(f, "%s %d\n", buf0, &x1);
		decode(buf0, buf3);
		printf("%s %d\n", buf3, x1);
	}
	for (int i = 0; i < n3; i++) {
		int x1;
		fscanf(f, "%s %d\n", buf0, &x1);
		decode(buf0, buf3);
		printf("%s %d\n", buf3, x1);
	}
}

void sub_205E5F0(FILE* f){
	int n18;
	fscanf(f, "%d ", &n18);
	printf("%d ", n18);
	for (int i = 0; i < n18; i++) {
		int x,y;
		fscanf(f, "(%d,%d) ", &x, &y);
		printf("(%d,%d) ",x,y);
	}
	puts("");
	fscanf(f, "\n");
}

void read_arch(FILE* f, Arch& a){
	// Stage 1
	fscanf(f, "%s %s %s %d %d %d %d %d %d %d %d %d %d\n", buf0, buf1, buf2, 
		&a.a, &a.b, &a.c, &a.d, &a.pfb, &a.bram, &a.dsps, &a.h, &a.pads, &a.j);
	decode(buf0, buf3);
	printf("%s ", buf3);
	decode(buf1, buf3);
	printf("%s ", buf3);
	decode(buf2, buf3);
	printf("%s %d %d %d %d %d %d %d %d %d %d\n", buf3, a.a, a.b, a.c, a.d, a.pfb, a.bram, a.dsps, a.h, a.pads, a.j);

	// Stage 3 sub_20619D0
	sub_20619D0(f);
	// Stage 4 sub_20627B0 main
	sub_20619D0(f);
	int n4, n5;
	fscanf(f, "%d %d\n", &n4, &n5);
	printf("%d %d\n", n4, n5);
	for (int i = 0; i < n4; i++) {
		int x;
		fscanf(f, "%d", &x); // push back
		printf("%d ", x);
	}
	for (int i = 0; i < n5; i++) {
		int x;
		fscanf(f, "%d", &x); // push back
		printf("%d ", x);
	}
	puts("");
	fscanf(f, "\n");

	int n6, n7, n8, n9;
	fscanf(f, "%d %d %d %d\n", &n6, &n7, &n8, &n9);
	printf("%d %d %d %d\n", n6, n7, n8, n9);
	
	for (int i = 0; i < n6; i++) {
		int x;
		fscanf(f, "%d %s\n", &x, buf0);
		decode(buf0, buf3);
		printf("%d %s\n", x, buf3);
	}
	for (int i = 0; i < n7; i++) {
		int x;
		fscanf(f, "%d %s\n", &x, buf0);
		decode(buf0, buf3);
		printf("%d %s\n", x, buf3);
	}
	for (int i = 0; i < n8; i++) {
		int x;
		fscanf(f, "%d %s\n", &x, buf0);
		decode(buf0, buf3);
		printf("%d %s\n", x, buf3);
	}
	for (int i = 0; i < n9; i++) {
		int x;
		fscanf(f, "%d %s\n", &x, buf0);
		decode(buf0, buf3);
		printf("%d %s\n", x, buf3);
	}
	//printf("\n");

	// stage 5 read_arch
	int n10;
	fscanf(f, "%d\n", &n10);
	printf("%d\n", n10);
	for (int i = 0; i < n10; i++) {
		int x;
		fscanf(f, "%d", &x); // push back
		printf("%d ", x);
	}
	puts("");
	fscanf(f, "\n");

	sub_2060230(f);
	sub_20619D0(f);
	// .85
	fscanf(f, "%d\n", &a.k);
	printf("%d\n", a.k);
	// stage 6 
	sub_2060230(f);
	sub_20619D0(f);
	sub_2060230(f);
	sub_20619D0(f);

	fscanf(f, "%d\n", &a.l); //.91
	printf("%d\n", a.l);
	sub_2060230(f);
	sub_2060230(f);
	sub_2060230(f);
	sub_2060230(f);
	sub_2060230(f);
	sub_2060230(f);
	sub_2060230(f);
	sub_2060230(f);
	sub_2060230(f);
	sub_2060230(f);
	sub_2060230(f);
	sub_2060230(f);
	sub_20619D0(f);

	fscanf(f, "%d\n", &a.m); //.107
	printf("%d\n", a.m);
	sub_2060230(f);
	sub_20619D0(f);

	fscanf(f, "%d\n", &a.n); //.110
	printf("%d\n", a.n);
	sub_2060230(f);
	sub_2060230(f);
	sub_2060230(f);
	sub_2060230(f);
	sub_2060230(f);
	sub_2060230(f);

//	debug(f);

	sub_205E5F0(f);
	sub_205E5F0(f);

	// debug(f);
}

void sub_47CC10(FILE *f) {
	int a1,a2,a3,a4,a5;
	fscanf(f, "%d %d %d %d %d\n", &a1, &a2, &a3, &a4, &a5);
	printf("%d %d %d %d %d\n", a1,a2,a3,a4,a5);
	for (int i = 0; i < a5; i++) {
		int a6;
		fscanf(f, "%s %d", buf0, &a6);
		decode(buf0, buf3);
		printf("%s %d ", buf3, a6);
		for (int j = 0; j < a6; j++) {
			fscanf(f, "%s", buf0);
			decode(buf0, buf3); // add to map
			printf("%s ", buf3);

		}
		puts("");
		fscanf(f, "\n");
	}
}
int xx[1024];
void sub_48C3F0(FILE *f){
	int a1; 
	fscanf(f, "%d", &a1);
	printf("%d ", a1);
	for (int i = 0; i < a1; i++) {
		fscanf(f, "%d", xx + i);
		printf("%d ", xx[i]);
	}
	fscanf(f, "\n");
	puts("");
	for (int i = 0; i < a1; i++) {
		for (int j = 0; j < xx[i]; j++) {
			int x1,x2;
			fscanf(f, "%s %d %d\n", buf0, &x1, &x2);
			decode(buf0, buf3);
			printf("%s %d %d\n", buf3, x1,x2); 
			for (int k = 0; k < x2; k++) {
				int x3,x4,x5;
				fscanf(f, "%d %s %d %d", &x3, buf0, &x4, &x5);
				decode(buf0, buf3);
				printf("%d %s %d %d ", x3, buf3,x4,x5);
			}
			puts("");
			fscanf(f, "\n");
		}
		//puts("");puts("");
	}
}

void sub_1FC60E0(FILE* f){
	// sub_1FC50D0
	int n1, n2, n3;
	fscanf(f, "%s %d %d %d\n", buf0, &n1, &n2, &n3);
	decode(buf0, buf3);
	printf("%s %d %d %d\n", buf3,n1,n2,n3); // == TimingLab

	for (int i = 0; i < n1; i++) {
		int a1,a2,a3,a4;
		fscanf(f, "%s %s %d %d %d %d\n", buf0, buf1, &a1, &a2, &a3, &a4);
		decode(buf0, buf3);
		printf("%s ", buf3);
		decode(buf1, buf3);
		printf("%s %d %d %d %d\n", buf3, a1,a2,a3,a4);
	}

	for (int i = 0; i < n2; i++) {
		int a1,a2;
		fscanf(f, "%s %s %d %d\n", buf0, buf1, &a1, &a2);
		decode(buf0, buf3);
		printf("%s ", buf3);
		decode(buf1, buf3);
		printf("%s %d %d\n", buf3,a1,a2);
		for (int j = 0; j < a1; j++) {
			int x1;
			fscanf(f, "%d", &x1);
			printf("%d ", x1);
		}
		fscanf(f, "\n");
		puts("");
		for (int j = 0; j < a2; j++) {
			int x1,x2,x3,x4;
			fscanf(f, "%d %d %d %d", &x1, &x2, &x3, &x4);
			printf("%d %d %d %d", x1,x2,x3,x4);
		}
		fscanf(f, "\n");
		puts("");
	}
	// debug(f);
	// TODO: fix not read all
	for (int i = 0; i < n3; i++) {
		int a1,a2,a3,a4;
		fscanf(f, "%s %d %d %d %d\n", buf0, &a1, &a2, &a3, &a4);
		decode(buf0, buf3);
		printf("%s %d %d %d %d\n", buf3, a1,a2,a3,a4);
		// this + 2 = a1
		for (int j = 0; j < a3; j++) {
			int x1;
			fscanf(f, "%d", &x1);
			printf("%d ", x1);
		}
		fscanf(f, "\n");
		puts("");
		for (int j = 0; j < a4; j++) {
			int x1;
			fscanf(f, "%d", &x1);
			printf("%d ", x1);
		}
		fscanf(f, "\n");
		puts("");
		// a3 == this + 7
		// a4 == this + 17

		for (int j = 0; j < a2; j++) {
			fscanf(f, "%s\n", buf0);
			decode(buf0, buf3);
			printf("%s\n", buf3);
			for (int x = 0; x < a3; x++)
				for (int y = 0; y < a4; y++) {
					int xy;
					fscanf(f, "%d", &xy);
					printf("%d ", xy);
				}
			fscanf(f, "\n");
			puts("");
		}
		fscanf(f, "\n");
		puts("");
	}
	//debug(f);
}

char buf1000a[1001];
char buf1000b[1001];

void sub_DE7290(FILE* f){
	int a1,a2,a3,a4,a5,a6,a7,a8;
	fscanf(f, "%s %s %d %d %d %d %d %d %d %d\n", buf0, buf1, &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8);
	decode(buf0, buf2);
	decode(buf1, buf3);
	printf("%s %s %d %d %d %d %d %d %d %d\n", buf2, buf3, a1,a2,a3,a4,a5,a6,a7,a8);

	fgets(buf1000a, 1000, f);
	fgets(buf1000b, 1000, f);
	printf("%s", buf1000a);
	printf("%s", buf1000b);

	for (int i = 0; i < a8; i++) {
		char c;
		fscanf(f, "%c %s\n", &c, buf0);
		decode(buf0, buf3);
		printf("%c %s\n", c, buf3);
	}

	fscanf(f, "\n");
	puts("");
}

void sub_DE8010(FILE* f){
	int n1; int a1,a2;
	fscanf(f, "%s %d %d %d\n", buf0, &a1, &a2, &n1);
	decode(buf0, buf3);
	printf("%s %d %d %d\n", buf3,a1,a2,n1);

	for (int i = 0; i < n1; i++) {
		sub_DE7290(f);
	}

	fscanf(f, "\n");
	puts("");
}

void sub_DE8530(FILE* f){
	int a1,a2,a3,a4,a5,a6,a7;
	fscanf(f, "%s %s %d %d %d %d %d %d %d\n",
    buf0,buf1,&a1,&a2,&a3,&a4,&a5,&a6,&a7);
    decode(buf0, buf3);
    decode(buf1, buf2);
    printf("%s %s %d %d %d %d %d %d %d\n", buf3, buf2,a1,a2,a3,a4,a5,a6,a7);
    fscanf(f, "\n");
    puts("");
}

void sub_DE9BC0(FILE* f){
	// sub_DE8CF0
	int n1;
	fscanf(f, "%s %d\n", buf0, &n1);
	decode(buf0, buf3);
	printf("%s %d\n", buf3, n1);
	if (string(buf3) != "bcc_info"){
		return ;
		// failed
	}
	for (int i = 0; i < n1; i++) {
		// sub_DE8010
		sub_DE8010(f);
	}
	fscanf(f, "\n");
	puts("");
	int xmax,ymax,a3,a4,a5,a6,a7;
	fscanf(f, "%s %d %d %d %d %d %d %d\n", buf0, &xmax, &ymax, &a3, &a4, &a5, &a6, &a7);
	decode(buf0, buf3);
	printf("%s %d %d %d %d %d %d %d\n", buf3, xmax, ymax, a3, a4, a5, a6, a7);
	// buf0 == 'bil_info' ?
	if (string(buf3) == "bil_info") {
		for (int x = 0; x < xmax; x++){
			for (int y = 0; y < ymax; y++) {
				int x1,y1,n2;
				fscanf(f, "%d %d %d\n", &x1, &y1, &n2);
				printf("%d %d %d\n", x1,y1,n2);
				if (x1 == x && y1 == y) {
					for (int j = 0; j < n2; j++) {
						sub_DE8530(f);
					}
				}else return; //failed
			}
		}

		fscanf(f, "\n");
		puts("");
		for (int i = 0;  i < a7; i++) {
			fscanf(f, "%s\n", buf0);
			decode(buf0, buf3);
			printf("%s\n", buf3);
		}
	}
}

void sub_DC2B30(FILE* f){
	int n1,n2,n3,n4;
	fscanf(f, "%d %d %d %d\n", &n1, &n2, &n3, &n4);
	printf("%d %d %d %d\n", n1, n2, n3, n4);
	for (int i = 0; i < n1; i++) {
		int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
		fscanf(f, "%d %d %d %d %d %d %d %d %d %d\n", &a1,&a2,&a3,&a4,&a5,&a6,&a7,&a8,&a9,&a10);
		printf("%d %d %d %d %d %d %d %d %d %d\n", a1,a2,a3,a4,a5,a6,a7,a8,a9,a10);
		for (int j = 0; j < a10; j++) {
			int x1;
			fscanf(f, "%d", &x1);
			printf("%d ", x1);
		}
		fscanf(f, "\n");
		puts("");
	}

	for (int i = 0; i < n2; i++) {
		fscanf(f, "%s\n", buf0);
		decode(buf0, buf3);
		printf("%s\n", buf3);
	}

}

void read_device(FILE *f){
	int n;
	fscanf(f, "%d\n", &n);
	printf("%d\n", n);
	// stage 1
	for (int i = 0; i < n; i++) {
		sub_47CC10(f);
	}
	for (int i = 0; i < 33; i++)
		sub_47CC10(f);
	// stage 2

	for (int i = 0; i < 56; i++) {
		sub_48C3F0(f);
	}

	// stage 3: sub_48CFD0 PPM?? 
	int n2;
	fscanf(f, "%d \n", &n2);
	printf("%d \n", n2);
	for (int i = 0; i < n2; i++) {
		int x1;
		fscanf(f, "%s %d \n", buf0, &x1);
		decode(buf0, buf3);
		printf("%s %d\n", buf3, x1);
	}

	// stage 4: sub_4CBD00  pads
	// 336 test_clk_sel test - - - -99 - - - -99 - - - -1901.24 1687.97
	// concated use " "
	// padn fnc type lqfp144 lqfp144_sip lqfp144_cfg lqfp144_bank qfn88 qfn88_sip qfn88_cfg qfn88_bank lvds_in lvds_out bs_order padx pady
	puts("");
	int n3;
	fscanf(f, "%d\n", &n3);
	printf("%d\n", n3);
	for (int i = 0; i < n3; i++) {
		int n4; fscanf(f, "%d", &n4);
		for (int j = 0; j < n4; j++) {
			fscanf(f, "%s", buf0);
			decode(buf0, buf3);
			printf("%s ", buf3);
		}
		fscanf(f, "\n");
		puts("");
	}

	// Stage 5. If xxx? .sub_4A2220 omitted

	// Stage 6.
	// pack?? 
	//sub_1F43E00(f);

	// kind of new
	int n4;
	fscanf(f, "pack %d\n", &n4);
	printf("pack %d\n", n4);
	while (n4) {
		// concat use \n ==> XML
		fscanf(f, "%s", buf0);
		decode(buf0, buf3);
		printf("%s\n", buf3);
		n4--;
	}
	fscanf(f, "%s", buf0);
	puts(buf0); // == kcap

	// timing lib
	sub_1FC60E0(f);

	// bitlib?
	sub_DE9BC0(f);
	// routing data??， optional?
	sub_DC2B30(f);
}

int main(){
	FILE *f = fopen("eagle_15.db", "rb");
	fscanf(f, "%d %s %d\n", &unknown_d1, arch, &nChips);
	printf("%d %s %d\n", unknown_d1, arch, nChips);
	lArch = strlen(arch);
	keyIdx = 0;
	for (int i = 0; i < nChips; i++) {
		read_arch(f, archs[i]);
		//return 0;
	}
	read_device(f);
	
	fclose(f);
}
