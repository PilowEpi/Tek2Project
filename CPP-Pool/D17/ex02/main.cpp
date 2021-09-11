#include "Cesar.hpp"
#include "OneTime.hpp"
#include <string>
#include <iostream>
static void encryptString ( IEncryptionMethod & encryptionMethod ,
    std::string const & toEncrypt )
    {
        size_t len = toEncrypt.size () ;
        encryptionMethod.reset () ;
    for ( size_t i = 0; i < len ; ++ i){
        encryptionMethod.encryptChar ( toEncrypt [ i ]) ;
    }
    std::cout << std::endl ;
}

static void decryptString ( IEncryptionMethod & encryptionMethod ,
std::string const & toDecrypt )
{
    size_t len = toDecrypt.size () ;
    encryptionMethod.reset () ;
    for ( size_t i = 0; i < len ; ++ i ) {
    encryptionMethod.decryptChar ( toDecrypt [ i ]) ;
    }
    std::cout << std::endl ;
}

int main ()
{
    OneTime o ("DedeATraversLesBrumes") ;
    OneTime t ("TheCakeIsALie") ;

    encryptString (o , "De la musique et du bruit !") ;
    decryptString (o , "Gi pa dunmhmp wu xg tuylx !") ;

     encryptString (t , "Kion li faras? Li studas kaj programas !") ;
     decryptString (t , "Dpsp vm xaciw? Pk cxcvad otq rrykzsmla !") ;

     encryptString (t , "Prend garde Lion, ne te trompes pas de voie !") ;
     decryptString (t , "Iyipd kijdp Pbvr, xi le bvhttgs tik om ovmg !") ;
    return 0;
}