-- GRAMMATICA:   L ::= [] | X : L

{- 1.1  UNIONE Di 2 LISTE
    Problema 1.1: date due liste pensate come
    insiemi, calcolare la lista che ne
    rappresenta l'unione

    Es. u (1 : 2 : []) (3 : 4 : []) =
    1 : 2 : 3 : 4 : []
    Soluzione: u l1 l2

    Parte meccanica (primo approccio)
    Ricorsione strutturale su l1
    union = u
    u [] l2 = ...
    u (x : l) l2 = ... u l ...
-}
u [] l2 = l2               -- CM1
u (x : l) l2 = x : u l l2  -- CM2

-- CM1: Una volta in "fondo" ad l1 basta restituire tutta l2.
-- CM2: Se l1 ha ancora qualche elemento, si ritorna quello in testa, seguito dal risultato della ricorsione.

{- 1.2  INSERIMENTO IN TESTA
    PRO 1.2: dati un elemento X e una lista
    di liste, aggiungere X in testa a tutte
    le liste contenute nella lista di liste
    
    Es. i 1 ((2 : 3 : []) : [] : []) =
    (1 : 2 : 3 : []) : (1 : []) : []
    Soluzione: hi el ll

    Primo approccio (parte meccanica)
    Ricorsione strutturale su ll (lista di liste)
    head_insert = hi
    hi el [] = []
    hi el (l : ll) = el : ... ll ...
-}
hi el [] = []                        -- CM1
hi el (l : ll) = (el : l) : hi el ll -- CM2

-- CM1: Non si aggiunge el alla fine della lista di liste.
-- CM2: Così si aggiunge el in testa a tutte le liste, comprese quelle vuote, caso: hi el ([] : [])

{- 1.0  SOTTOINSIEMI
    Problema 1: data una lista L di numeri
    pensata come un insieme, calcolare
    l'insieme delle parti di L visto come
    lista di liste di numeri

    Es. p (1 : 2 : []) =
    [] : (1 : []) : (2 : []) : (1 : 2 : []) : []
    Soluzione: p l
    
    Primo approccio (parte meccanica)
    Ricorsione strutturale su l (ovvio in qunato unico argomento)
    p [] = ...
    p (x : l) = ... p l ...
-}
p [] = [] : []
p (x : l) = u (p l) (hi x (p l))

------------------------------------------------------------------------------

{- 2.1  INSERIMENTO IN OGNI POSIZIONE
    Problema 4: dati un elemento x e una lista l,
    restituire la lista di tutti i possibili modi
    di inserire x in l

    Es ins 1 (2 : 3 : []) =
    1 : 2 : 3 : []) :
    (2 : 1 : 3 : []) :
    (2 : 3 : 1 : []) : []
    Soluzione: ins el l
    
    Ricorsione strutturale su l
    ins el [] = ...
    ins el (x : l) = ... ins ? l ...
-}
ins el [] = (el : []) : [] -- CM1
ins el (x : l) = (el : x : l) : hi x (ins el l) -- CM2

-- CM1: Cercando di inserire x in una lista vuota si ottiene x (dunque x : [] per inserire x, e [] per la fine della lista).
-- CM2: 

{- 2.2  APPLICA UNA FUNZIONE AGLI ELEMENTI DI UNA LISTA
    Questa funzione serve per applicare 2.1 ad ogni lista di 2.0, in
    modo tale da ...........

    Problema 5: data una lista di elementi
    x1 : ... : xn : [] e una funzione f 
    restituire la lista
    f x1 : ... : f xn : []
    Es. map double (2 : 3 : 4 : []) = 4 : 6 : 8 : []
    Soluzione: map f l1

    Ricorsione strutturale su f l
    map f [] = []
    map f (x : l) = ... map f l ...

-}
mmap f [] = []                    -- CM1
mmap f (x : l) = f x : mmap f l   -- CM2

double x = x * 2 -- Test function (map double (1 : 2 : []))

-- CM1: Alla lista vuota non bisogna applicare acluna funzione
-- CM2: Si applica la funzione f all'elemento in testa e si procede con il successivo

{- 2.3  UNIONE DI LISTE DI LISTE
    Problema 6: data una lista di liste,
    calcolare l'unione di tutte le liste
    nella liste di liste

    Es. uu ((1 : 2 : []) : (3 : []) : (4 : []) : []) =
    1 : 2 : 3 : 4 : []
    Soluzione: uu ll

    lista di liste = ll
    Ricorsione strutturale su l
    uu ll = []
    uu (l : ll) = ... uu ll ...

-}
uu [] = []                  -- CM1
uu (l : ll) = u l (uu ll)   -- CM2

-- CM1: L'unione delle liste vuote è una lista vuota
-- CM2: 


{- 2.0  PERMUTAZIONI
    Problema 7: data una lista L di numeri
    calcolare tutte le permutazioni di l
    rappresentate come lista di liste

    Es perm (1 : 2 : 3 : []) =
    (1 : 2 : 3 : []) :
    (1 : 3 : 2 : []) :
    (2 : 1 : 3 : []) :
    (2 : 3 : 1 : []) :
    (3 : 1 : 2 : []) :
    (3 : 2 : 1 : []) : []
    Soluzione: perm l
-}
-- perm [] = [] : [] -- CM1
-- perm (x : l) = 

-- CM1: L'insieme di tutte le permutazioni della lista vuotà è il singoletto contenente solo la lista vuota.