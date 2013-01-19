#include <stdio.h>
#include "htmlblockbase.h"
#include "htmlblockfactory.h"

using namespace std;

int main()
{
//    htmlBlockText       sText("Test");
    htmlBlockP*         pPara = htmlBlockFactory::P("Test", emptyString, "mast");

    pPara->AddText("\nContinued!");

    STRING_T sHTML = pPara->HTML();

    printf("%s\n", sHTML.c_str());

    delete pPara;

    return 0;
}
