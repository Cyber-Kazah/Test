
#include "TXLib.h"

struct Forma
{
    string text_q;
    int r_ans;
        HDC pic1;
    string text_ans1;

        HDC pic2;
    string text_ans2;

        HDC pic3;
    string text_ans3;
};

void drawAns(int x, HDC pic, string text_ans)
{
    txSelectFont("Times New Roman", 40);
    txDrawText  (x, 550, x+380, 890, text_ans.c_str());
    txRectangle (x, 350, x+380, 690);
    txBitBlt(txDC(), x, 350, 380, 340, pic);
}

bool clickAns(int x)
{
 return( txMouseButtons() == 1 && txMouseX() > x && txMouseX() < x+380 && txMouseY() > 350 && txMouseY() > 690);

}

 //сюжет тим фортресс 2
int main()
    {
    txCreateWindow (1700, 900);

    int kol_q = 2;
    Forma q_buf;
    Forma q[kol_q];
    q[0] = {"Кто написал завещание братьям Манн?", 2, txLoadImage("Pic/Zep.bmp"), "Зефеная Манн", txLoadImage("Pic/Grey.bmp"), "Грей Манн",  txLoadImage ("Pic/Sax.bmp"), "Сакстон Хэил"};
    q[1] = {"Кто сосед Солдата?", 3, txLoadImage ("Pic/Mom.bmp"), "Мама Подрывника", txLoadImage ("Pic/SC.bmp"), "Разведчик", txLoadImage ("Pic/Mar.bmp"), "Маразмус"};
    int n_q = 1;
    int kol_r_ans = 0;

    while(true)
    {
     txSetColor(TX_WHITE, 5);
     txSetFillColor(TX_BLACK);
     txClear();
     txBegin;

    q_buf = q[n_q - 1];

    //вопрос
     txDrawText(0, 0, 1900, 200, q_buf.text_q.c_str());
     drawAns(200, q_buf.pic1, q_buf.text_ans1);
     drawAns(700, q_buf.pic2, q_buf.text_ans2);
     drawAns(1200, q_buf.pic3, q_buf.text_ans3);

    if( txMouseButtons() == 1 &&
        txMouseX() > 200 && txMouseX() < 580 &&
        txMouseY() > 350 && txMouseY() < 690)
    {
        n_q++;
        txSleep(200);

    }
     if(clickAns(200))
     {
       if(q_buf.r_ans == 1) kol_r_ans++;
       txSleep(200);
       n_q++;
     }

     if(clickAns(700))
     {
       if(q_buf.r_ans == 2) kol_r_ans++;
       txSleep(200);
       n_q++;
     }

     if(clickAns(1200))
     {
       if(q_buf.r_ans == 3) kol_r_ans++;
       txSleep(200);
       n_q++;
     }
     txEnd;
     txSleep(20);
    }

    txTextCursor (false);
    return 0;
    }

