Marinescu Maria-Catalina 324CA - Tema1

--------------------------------------------------------------------------------

Feribot: 
  Pentru a rezolva problema am folosit algoritmul "divide et impera".
  In rezolvarea problemei am folosit ideea algoritmului de binary search
implementata in laboratorul de pe ocw.  
  Astfel, solutia problemei se afla in intervalul ce are ca si capat inferior 
elementul maxim din vector, iar ca cel superior suma tuturor elementelor.
Am considerat mijlocul intervalului ca fiind suma celor doua capete de interval 
impartita la 2 si am inceput cautarea solutiei. Am verificat care ar fi cea 
mai buna solutie de impartire a masinilor, pentru care s-ar umple toate
feriboturile iar in functie de unde se pozitiona fiecare solutie in interval,
modificam capetele. 
  Complexitatea algoritmului este O(n * log(sum(w))), n fiind numarul de
elemente din vectorul w iar sum(w) suma elementelor din w.   
  
--------------------------------------------------------------------------------

Nostory:
Pentru a rezolva problema am folosit algoritmul Greedy pentru ambele task-uri.
-Task1:
  Pentru cazul in care avem un numar nelimitat de mutari am sortat cei doi 
vectori crescator si am comparat fiecare element din prima lista cu 
corespondentul sau din a doua lista si am vazut care dintre ele este mai mare si
pe acela l-am adunat la scorul final.
  Complexitatea in acest caz este O(n * log(n)).  

-Task2:
  Pentru cazul in care avem un numar limitat de mutari am interschimbat 
elementele din cei doi vectori astfel incat in vectorul a sa fie maximele, iar
in b sa fie minimele. Am sortat vectorul b descrescator si pe a crescator pentru
a vedea si apoi le-am parcurs pentru a vedea cu cine am putea schimba cel mai 
mare minim din momentul respectiv. Acest lucru se repeta pana nu maiavem mutari.
  Complexitatea in acest caz este O(n * log(n)).
   
--------------------------------------------------------------------------------

Sushi:
  Pentru a rezolva problema am folosit algoritmul de programare dinamica.
Aceasta problema functioneaza pe acelasi principiu ca problema rucsacului, de 
aceea am preluat implementarea problemei rucsacului din laboratorul de pe ocw si
i-am adus mici modificari pentru a satiface cerintele problemei. Astfel:
  -pentru task-ul 1 am folosit algortimul problemei rucsacului si am calculat
suma notelor pentru fiecare posibilitate de comandare a unui platou.  
  -pentru task-ul 2 am initializat o variabila plates cu 1 pentru a respecta 
restrictia de cel mult 2 platouri, astfel atunci cand verificam pretul unui
platou inmulteam cu plates, cat timp plates nu devenea mai mare ca 2.
  -pentru task-ul 3 am adaugat o a treia dimensiune matricei dp ce reprezinta
numarul maxim de platouri ce pot fi comandate si am luat o variabila nr ce la
fiecare posibilitate de cumparare a platourilor numara cate platouri sunt. 
Astfel, la fiecare pas verific daca numarul total posibil de platouri este mai 
mic decat numarul permis de platouri.  
  Complexitatea algoritmului este pentru task-urile 1 si 2 O(m * n * x) si 
pentru task-ul 3 O(m * n * n * x). 
 
--------------------------------------------------------------------------------

Semnale:
  Pentru a rezolva problema am folosit algoritmul de programare dinaminca.
  Ca mod de rezolvare, am abordat un tip asemanator cu problema 
"gardurilor lui Gigel" din laboratorul de pe ocw. Astfel, ambele task-uri am
considerat matricea dp ce doua dimensiuni, una pentru zero-uri si cealalta 
pentru unu. Am vazut care ar fi cazurile de baza, adica in functie de cati de 1 
si 0 am avea pentru inceput (ori niciunul, ori unul din fiecare) si cate 
"semnale" am putea forma. Apoi am gasit formula de recurenta in functie de
ultima cifra adaugata semnalului, daca adaugam 0 nu ne intereseaza ce este
inainte, pe cand daca adaugam 1 trebuie sa tinem cont de ce a fost in spate.
  Complexitatea acestui algoritm pentru ambele task-uri este O(x * y).
  
--------------------------------------------------------------------------------
