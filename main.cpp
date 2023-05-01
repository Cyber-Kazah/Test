
#include "TXLib.h"
 //сюжет тим фортресс 2
int main()
    {
    txCreateWindow (1900, 900);

    HDC Zph = txLoadImage("Pic/Zep.bmp");
    HDC Grey = txLoadImage("Pic/Grey.bmp");
    HDC Sax = txLoadImage ("Pic/Sax.bmp");

    string text_q1 = "Кто написал завещание братьям Манн?";
    HDC pic1 = Zph;
    string text_ans1 = "Зефеная Манн";

    HDC pic2 = Grey;
    string text_ans2 = "Грей Манн";

    HDC pic3 = Sax;
    string text_ans3 = "Сакстон Хэил";





    //вопрос
    txSelectFont("Times New Roman", 40);
    txDrawText(0, 0, 1900, 200, text_q1.c_str());

    txDrawText(200, 550, 580, 890, text_ans1.c_str());
        txRectangle (200, 350, 580, 690);
    txBitBlt(txDC(), 200, 350, 380, 340, Zph);

    txDrawText(700, 550, 1080, 890, text_ans2.c_str());
        txRectangle (700, 350, 1080, 690);
    txBitBlt(txDC(), 700, 350, 380, 340, Grey);

    txDrawText(1200, 550, 1580, 890, text_ans3.c_str());
        txRectangle (1200, 350, 1580, 690);
    txBitBlt(txDC(), 1200, 350, 380, 340, Sax);

    txTextCursor (false);
    return 0;
    }

