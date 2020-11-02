# befunge-93
a befunge-93 interpreter 

# building
to build the program run `make`

# examples
* `b93 tests/mandelbrot.b93` will run `tests/mandelbrot.b93` and output:
```}}}}}}}}}|||||||{{{{{{{{{{{{{{{{{{{{{{{{{{zzzzzzzzzyyyyxwusjuthwyzzzzzzz{{{{{{{
}}}}}}}}|||||||{{{{{{{{{{{{{{{{{{{{{{{{{zzzzzzzzzzyyyyxwwvtqptvwxyyzzzzzzz{{{{{
}}}}}}}||||||{{{{{{{{{{{{{{{{{{{{{{{{{zzzzzzzzzzzyyyyxwvuqaZlnvwxyyyzzzzzzz{{{{
}}}}}}|||||{{{{{{{{{{{{{{{{{{{{{{{{{zzzzzzzzzzzyyyyxxvqXp^g Ynslvxyyyyyzzzzz{{{
}}}}}}||||{{{{{{{{{{{{{{{{{{{{{{{{zzzzzzzzzzzyyyxxxxwvtp      6puwxyyyyyyzzzz{{
}}}}}||||{{{{{{{{{{{{{{{{{{{{{{{zzzzzzzzzzyyyxxxxxwwvvqc      &8uvwxxxyyyyyzzz{
}}}}|||{{{{{{{{{{{{{{{{{{{{{{{zzzzzzzzzyyyywwvtvvvvuutsp      Hrtuuvwxxxxwqxyzz
}}}}||{{{{{{{{{{{{{{{{{{{{{{zzzzzzzzyyyyyxwvqemrttj m id+    PRUiPp_rvvvvudwxyz
}}}||{{{{{{{{{{{{{{{{{{{{{zzzzzzyyyyyyyxxxwurf  ZnW                4nrslnobgwyy
}}}||{{{{{{{{{{{{{{{{{{{zzzzyyyyyyyyyyxxxwvusg                        N  Uquxyy
}}||{{{{{{{{{{{{{{{{{zzzzyyyyyyyyyyyxxxxwvrrrkC                          grwxxy
}}|{{{{{{{{{{{{{{{zzzzyxxxxxyyyyyxxxxxwwukM!f                            ptvwxy
}}|{{{{{{{{{{zzzzzzyyxwsuwwwwwwwwwwwwwvvurn[                              ptuox
}|{{{{{{{zzzzzzzzyyyxxvptuuvvumsuvvvvvvu`                                   hjx
}|{{{{zzzzzzzzzyyyyyxxwusogoqsqg]pptuuttlc                                 ntwx
}{{{zzzzzzzzzyyyyyyxxwwuto  -    O jpssrO                                  nsvx
}{{zzzzzzzzzyyyyyyxwwwvrrT4          TonR                                  Ufwy
}{zzzzzzzzyyyyyxxwttuutqe             Dj                                   $uxy
}zzzzzzzzyxxxxxwwvuppnpn               `                                   twxy
}yyyxxwvwwwxwvvvrtppc  Y                                                 auwxxy
                                                                       dqtvwxyy
}yyyxxwvwwwxwvvvrtppc  Y                                                 auwxxy
}zzzzzzzzyxxxxxwwvuppnpn               `                                   twxy
}{zzzzzzzzyyyyyxxwttuutqe             Dj                                   $uxy
}{{zzzzzzzzzyyyyyyxwwwvrrT4          TonR                                  Ufwy
}{{{zzzzzzzzzyyyyyyxxwwuto  -    O jpssrO                                  nsvx
}|{{{{zzzzzzzzzyyyyyxxwusogoqsqg]pptuuttlc                                 ntwx
}|{{{{{{{zzzzzzzzyyyxxvptuuvvumsuvvvvvvu`                                   hjx
}}|{{{{{{{{{{zzzzzzyyxwsuwwwwwwwwwwwwwvvurn[                              ptuox
}}|{{{{{{{{{{{{{{{zzzzyxxxxxyyyyyxxxxxwwukM!f                            ptvwxy
}}||{{{{{{{{{{{{{{{{{zzzzyyyyyyyyyyyxxxxwvrrrkC                          grwxxy
}}}||{{{{{{{{{{{{{{{{{{{zzzzyyyyyyyyyyxxxwvusg                        N  Uquxyy
}}}||{{{{{{{{{{{{{{{{{{{{{zzzzzzyyyyyyyxxxwurf  ZnW                4nrslnobgwyy
}}}}||{{{{{{{{{{{{{{{{{{{{{{zzzzzzzzyyyyyxwvqemrttj m id+    PRUiPp_rvvvvudwxyz
}}}}|||{{{{{{{{{{{{{{{{{{{{{{{zzzzzzzzzyyyywwvtvvvvuutsp      Hrtuuvwxxxxwqxyzz
}}}}}||||{{{{{{{{{{{{{{{{{{{{{{{zzzzzzzzzzyyyxxxxxwwvvqc      &8uvwxxxyyyyyzzz{
}}}}}}||||{{{{{{{{{{{{{{{{{{{{{{{{zzzzzzzzzzzyyyxxxxwvtp      6puwxyyyyyyzzzz{{
}}}}}}|||||{{{{{{{{{{{{{{{{{{{{{{{{{zzzzzzzzzzzyyyyxxvqXp^g Ynslvxyyyyyzzzzz{{{
}}}}}}}||||||{{{{{{{{{{{{{{{{{{{{{{{{{zzzzzzzzzzzyyyyxwvuqaZlnvwxyyyzzzzzzz{{{{
}}}}}}}}|||||||{{{{{{{{{{{{{{{{{{{{{{{{{zzzzzzzzzzyyyyxwwvtqptvwxyyzzzzzzz{{{{{
}}}}}}}}}|||||||{{{{{{{{{{{{{{{{{{{{{{{{{{zzzzzzzzzyyyyxwusjuthwyzzzzzzz{{{{{{{
```

* `b93 --extensions=true test/soup.b93` will run `tests/soup.b93` with extensions enabled and output:
```
      GHIJKLM                                                           UVWXYZA
    FGHIJKLMNOP                                                         VWXYZAB
  EFGHIJKLMNOPQR                                                        WXYZABC
 EFGHIJKLMNOPQRST                                                       XYZABCD
 FGHIJKL   PQRSTU         EFGHIJ      QRSTUV    ABCDEF HIJKL  OPQRS     YZABCDE
 GHIJKLM               CDEFGHIJKLM    RSTUVW    BCDEFG IJKLMNOPQRSTUV   ZABCDEF
 HIJKLMNOPQR          CDEFGHIJKLMNO   STUVWX    CDEFGH JKLMNOPQRSTUVW   ABCDEFG
  JKLMNOPQRSTUV      CDEFGH   LMNOPQ  TUVWXY    DEFGHI KLMNOPQRSTUVWXY  BCDEFGH
   LMNOPQRSTUVWXY    DEFGH     NOPQR  UVWXYZ    EFGHIJ LMNOPQ   UVWXYZ   DEFG I
     OPQRSTUVWXYZA  DEFGHI     OPQRST VWXYZA    FGHIJK MNOPQ     WXYZAB  EFGH J
        STUVWXYZAB  EFGHIJ     PQRSTU WXYZAB    GHIJKL NOPQR     XYZABC  FGHI K
           WXYZABCD FGHIJK     QRSTUV XYZABC    HIJKLM OPQRS     YZABCD  GHIJ L
MNOPQRS     YZABCDE GHIJKL     RSTUVW YZABCD    IJKLMN PQRST     ZABCDE       M
NOPQRSTU   YZABCDEF HIJKLM     STUVWX ZABCDEF  IJKLMNO QRSTU     ABCDEF HIJKLMN
 PQRSTUVWXYZABCDEF   JKLMNO   STUVWX  ABCDEFGHIJKLMNOP RSTUVW   ABCDEFG IJKLMNO
  RSTUVWXYZABCDEF     LMNOPQRSTUVWX    CDEFGHIJKLMNOPQ STUVWXYZABCDEFG  JKLMNOP
   TUVWXYZABCDEF       NOPQRSTUVWX     DEFGHIJK MNOPQR TUVWXYZABCDEFG   KLMNOPQ
      XYZABCDE           QRSTUVW         GHIJK  NOPQRS UVWXY  BCDEF     LMNOPQR
                                                       VWXYZ                  S
                                                       WXYZA                  T
                                                       XYZAB                  U
                                                       YZABC                  V
```
