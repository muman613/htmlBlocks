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

    pHTML->Head()->AddTitle("Sample HTML");
    pHTML->AddToBody( htmlBlockFactory::H1("Heading #1") );
    pHTML->Body()->AddCRLF();
    pHTML->AddToBody( htmlBlockFactory::P("This is an example paragraph. "
                                          "It can contain a whole lot of text if you want it to. "
                                          "But it can also contain a little text.") );
    pHTML->Body()->AddCRLF();
    pHTML->AddToBody(htmlBlockFactory::H2("Heading #2"));
    pHTML->Body()->AddCRLF();
    pHTML->Body()->AddText("No shiff");
    STRING_T sHTML = pHTML->HTML();

    printf("%s\n", sHTML.c_str());

    return 0;
}
