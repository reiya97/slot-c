#include <stdio.h>
#include <stdlib.h>//    srand()
#include <time.h>//      time()
#include <unistd.h>//    usleep()

void fanc1(void) {
    printf("            +---------+\n");
    printf("            |    |    |\n");
    printf("            |    |    |\n");
    printf("            |    |    |\n");
    printf("            |    |    |\n");
    printf("            |    |    |\n");
    printf("            +---------+\n");
}

void fanc2(void) {
    printf("            +---------+\n");
    printf("            |  ----+  |\n");
    printf("            |      |  |\n");
    printf("            |  +---+  |\n");
    printf("            |  |      |\n");
    printf("            |  +----  |\n");
    printf("            +---------+\n");
}

void fanc3(void) {
    printf("            +---------+\n");
    printf("            |  ----+  |\n");
    printf("            |      |  |\n");
    printf("            |  ----+  |\n");
    printf("            |      |  |\n");
    printf("            |  ----+  |\n");
    printf("            +---------+\n");
}

void hit(void) {
    printf("===================================\n");
    printf("  |      |       |      ----+----  \n");
    printf("  |      |       |          |      \n");
    printf("  +------+       |          |      \n");
    printf("  |      |       |          |      \n");
    printf("  |      |       |          |      \n");
    printf("===================================\n\n");
}

void reach(void) {
    printf("=================================================\n");
    printf("  +----    +-----      /\\        ---\\   |      | \n");
    printf("  |    |   |          /  \\      /       |      | \n");
    printf("  |----    +-----    /----\\    |        +------+ \n");
    printf("  |  \\     |        /      \\    \\       |      | \n");
    printf("  |   \\    +-----  /        \\    ---/   |      | \n");
    printf("=================================================\n\n");
}

int main(int argc, const char * argv[]) {
    
    int array[10][10] = {
        {1,1,1,1,1,1,1,1,2,3},
        {1,1,1,1,1,1,1,1,2,3},
        {1,1,1,1,1,1,1,1,2,3},
        {1,1,1,1,1,1,1,1,2,3},
        {1,1,1,1,1,1,1,1,2,3},//1が当たる確率が高い行が選ばれる確率は２分の１
        {1,2,2,2,2,2,2,2,2,3},
        {1,2,2,2,2,2,2,2,2,3},
        {1,2,2,2,2,2,2,2,2,3},//2が当たる確率が高い行が選ばれる確率は１０分の３
        {1,2,3,3,3,3,3,3,3,3},
        {1,2,3,3,3,3,3,3,3,3},//3が当たる確率が高い行が選ばれる確率は５分の１
    };
    int array0[4];//     出力要素
    int nokori = 5;//    残りのコイン枚数
    int n;
    int m;//   コイン投入枚数
    int get;
//    int second = 1;
    
    printf("        +------------------+\n");
    printf("        |  スロットゲーム  |\n");
    printf("        +------------------+\n");
    
    printf("    **          配当          **\n");
    printf("   ==============================\n");
    
    printf("            +---------+\n");
    printf("            |    |    |\n");
    printf("            |    |    |\n");
    printf("            |    |    | ====>  x 3コイン獲得\n");
    printf("            |    |    |\n");
    printf("            |    |    |\n");
    printf("            +---------+\n");
    
    printf("            +---------+\n");
    printf("            |  ----+  |\n");
    printf("            |      |  |\n");
    printf("            |  +---+  | ====>  x 10コイン獲得\n");
    printf("            |  |      |\n");
    printf("            |  +----  |\n");
    printf("            +---------+\n");
    
    printf("            +---------+\n");
    printf("            |  ----+  |\n");
    printf("            |      |  |\n");
    printf("            |  ----+  | ====>  x 30コイン獲得\n");
    printf("            |      |  |\n");
    printf("            |  ----+  |\n");
    printf("            +---------+\n");
    printf("   ==============================\n");
    
    while (nokori != 0) { //        残りコインが0になるまでループ
        printf("\n         入力してください\n");
        printf("       +------------------+\n");
        printf("　     | 1:回す | 2:やめる|\n");
        printf("       +------------------+\n\n");
        
        printf("         入力(1 or 2): ");scanf("%d", &n);//  選択
        
        if(n!=1&&n!=2){ //      1と2以外の場合終了
            printf("         1か2で答えてください\n");
            break;
        }
        if(n==2)break;//   終了
        printf("\n       +--------------+-----+\n");
        printf("       | コイン所持数 | %d枚|\n", nokori);
        printf("       +--------------+-----+\n");
        
        while(1) {//               投入枚数が残りの枚数以下の場合のみスタート可能
            printf("        コイン投入枚数(0を入力→全て）: ");scanf("%d", &m);//    投入枚数
            if(m<0) {
                printf("\n        正しく入力してください\n");
                continue;
            }
            if(nokori>=m) break;
            printf("\n        コインが足りません\n");
        }
        
        if(m==0) m = nokori;
        
        nokori-= m;
        srand((unsigned int)time(NULL));//    現在時刻を使って初期化
        
        printf("\n\n         #===============#\n");
        int j = rand() % 10;//         0~9のランダムな整数値を使って行を選択
//        printf("j=%d\n", j);
        for(int i = 0; i < 3; i++) {
            int k = rand() % 10;//         0~9のランダムな整数値を使って列を選択
//            printf("k=%d\n", k);
            array0[i] = array[j][k];
            if (array0[i]==1)fanc1();
            if (array0[i]==2)fanc2();
            if (array0[i]==3)fanc3();
            usleep(500000);//    time()関数で使う時刻をかえるために0.5秒待機 + デザイン
            if(array0[0]==array0[1]&&i==1){
                reach();
                usleep(1500000);//  1.5秒
            }
        }
        printf("         #===============#\n");
        usleep(500000);
        
        
        if(array0[0]==1&&array0[1]==1&&array0[2]==1){//　　　　選ばれた３つの要素が1の時
            hit();
            get = 3*m;
            nokori+=get;
            printf("        ** %dコインゲット！**\n\n", get);
            get = 0;//初期化
        }
        
        if(array0[0]==2&&array0[1]==2&&array0[2]==2){//    　選ばれた３つの要素が2の時
            hit();
            get = 10*m;
            nokori+=get;
            printf("        ** %dコインゲット！**\n\n",get);
            get = 0;//初期化
        }
        
        if(array0[0]==3&&array0[1]==3&&array0[2]==3){//　　　選ばれた３つの要素が3の時
            hit();
            get = 30*m;
            nokori += get;
            printf("        ** %dコインゲット！**\n\n", get);
            get = 0;//初期化
        }
        for(int l=0; l<3; l++) array0[l] = 0;//array0を初期化
    }
    
    printf("\n          終了しました。\n\n");
    
    return 0;
}
