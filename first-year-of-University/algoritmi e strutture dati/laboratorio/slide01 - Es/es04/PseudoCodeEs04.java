/*  EXERCISES TEXT
    Si scriva una procedura ricorsiva che data una lista L di
    interi, la modifichi eliminando ogni elemento pari e
    replicando ogni elemento dispari tante volte quanti sono
    gli elementi pari che lo precedono
    • Esempio: L = 4; 6; 7; 3; 2; 5, allora si ha L = 7; 7; 7; 3; 3; 
    3; 5; 5; 5; 5.
    • Scrivere lo pseudocodice della procedura nel caso di lista 
    concatenata monodirezionale
*/

/*  PSEUDOCODE

isEven [] = null        // Case not defined
isEven x = x % 2 == 0 

Problema 2:
    Data una lista l ritornare la quantità di volte che un numero
    pari precede il primo numero dispari.

    Esempio:
        (1 : 3 : 5 : 8 : 1 : 2) = 3
        (1 : 2 : 3 : 4) = 1

evenNumbers [] = 0
evenNumbers (x : l) =
    if isEven x
        then 1 + evenNumbers l
    else 0

Problema 3:
    Date i parametri times e value (times > 0), restituire una lista contenente
    il valore value n-times

    Esempio:
        2 5 = 5 5
        5 3 = 3 3 3 3 3
        4 7 = 7 7 7 7

oddNumbers 1 v = v
oddNumbers t v = v : oddNumbers (t-1) v



// DA FINIRE




es04 [] = []
es04 (x : l) =
    if isEven x
        then 
    else 

*/



