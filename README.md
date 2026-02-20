::CRONOGRAMA::

3.- COFRES ESTÄTICOS

○ Quan el personatge entra en una casella amb un cofre (C), pot obrir-lo i obtenir:

■ Una quantitat d’or entre 10 i 100.

■ Un objecte del arxiu items.txt que augmenta la probabilitat de victòria en
combat

4.- Enemics estàtics i combats:

○ Si el personatge trepitja la casella d’un enemic (E), comença un combat simple.

○ El personatge té 3 vides totals; cada derrota en combat resta 1 vida. Si s’arriba a
0, el joc acaba amb derrota.

○ La probabilitat de guanyar un combat és 1/3 + (bonificació de
l’objecte).

○ Si es guanyen tots els combats (s’eliminen tots els enemics), el joc acaba amb
victòria.

6.- Fitxer de detalls d’ítems (items.txt):

Aquest fitxer conté un llistat d’objectes possibles (mínim 5 )amb la seva bonificació en combat..

PocióAtac 0.15

EscutMàgic 0.20

. . .

En obrir un cofre, s’assigna un d’aquests ítems de forma aleatòria, i al jugador se li aplica la
bonificació de forma permanent. S’ha d’avisar al jugador de l’item i la quantitat d’or
conseguit.

6.- Guardar i carregar partida (fitxer binari “partida.dat”):

○ Cal poder desar en qualsevol moment:

■ El nom del jugador (se li pregunta al moment de guardar).

■ Una estructura amb:

- El nom del jugador.

- La posició actual (P) dins la sala.

- El nombre de vides que li queden.

- L’or acumulat.

- El percentatge total d’atac aconseguit.

○ S’ha de poder reprendre la partida llegint la informació del fitxer binari i
reconstruint l’estat original del joc al iniciar l'aplicació.

Menú inicial:

1. Nova partida

2. Carregar partida

3. Sortir
