#include <stdio.h>
#include "htmlblockbase.h"
#include "htmlblockfactory.h"

using namespace std;

#if 0

    htmlBlockP*         pPara = htmlBlockFactory::P("Test", emptyString, "mast");

    pPara->AddText("\nContinued!");

    STRING_T sHTML = pPara->HTML();

    printf("%s\n", sHTML.c_str());

    delete pPara;

#endif

int main()
{
//    htmlBlockText       sText("Test");

    htmlBlockHTML           *pHTML;

    pHTML = new htmlBlockHTML();

    pHTML->AddToBody( htmlBlockFactory::H1("Heading #1") );
    pHTML->Body()->AddCRLF();
    pHTML->AddToBody( htmlBlockFactory::P("This is the text") );
    pHTML->Body()->AddCRLF();

    STRING_T sHTML = pHTML->HTML();

    printf("%s\n", sHTML.c_str());

    return 0;
}
