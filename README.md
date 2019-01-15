 C’est quoi, le Corewar ?
 
• Le Corewar est un jeu très particulier. Il consiste à rassembler autour d’une "machine virtuelle" des "joueurs", lesquels vont y charger des "champions" qui vont se
battre à l’aide de "processus", dans le but, entre autres, de faire en sorte qu’on dise
d’eux qu’ils sont "en vie".

• Les processus s’exécutent séquentiellement au sein de la même machine virtuelle,
et du même espace mémoire. Ils peuvent donc, entre autre chose, s’écrire les uns
sur les autres afin de se corrompre mutuellement, de forcer les autres à exécuter
des instructions qui leur font du mal, de tenter de recréer à la volée l’équivalent
logiciel d’un Côtes du Rhône 1982, etc ...

• Le jeu se termine quand plus aucun processus n’est en vie. À ce moment là, le
gagnant est le dernier joueur à avoir été rapporté comme étant "en vie".


Le projet consiste à rendre trois parties distinctes :

• L’assembleur : C’est le programme qui va compiler vos champions et les traduire
du langage dans lequel vous allez les écrire (l’assembleur) vers un "bytecode", à
savoir un code machine qui sera directement interprété par la machine virtuelle.

• La machine virtuelle : C’est l’"arène" dans laquelle les champions vont s’exécuter. Elle offre de nombreuses fonctionnalités, toutes utiles au combat des champions. Il va de soi qu’elle permet d’exécuter plusieurs processus en simultané ; on
vous demande une arène, pas un simulateur de one-man show.

• Le champion : C’est un cas un peu particulier. Plus tard, pour le championnat,
vous allez devoir rendre un champion si puissant et effrayant qu’il ferait trembler
de peur un bocalien. Cependant, comme cela constitue en soi un travail conséquent, et que pour l’instant on est juste intéressés par votre capacité à réaliser les
autres programmes du Corewar, et que votre champion du moment ne sert qu’à
nous prouver que vous savez écrire des bouts d’ASM de Corewar, le champion à
rendre dans le cadre de ce projet précis n’a besoin d’effrayer qu’un hérisson neurasthénique.


La machine virtuelle

• Chaque processus aura à sa disposition les éléments suivants, qui lui sont propres :
  ◦ REG_NUMBER registres qui font chacun une taille de REG_SIZE octets.
  Un registre est une petite "case" mémoire, qui ne contient qu’une seule valeur.
  Sur une vraie machine, elle est interne au processeur et est donc TRÈS rapide
  d’accès.
  ◦ Un PC ("Program Counter"). C’est un registre spécial, qui contient juste l’adresse,
  dans la mémoire de la machine virtuelle, de la prochaine instruction à décoder et exécuter. Très utile pour savoir où l’on se trouve dans l’exécution, afin
  d’écrire des choses en mémoire...
  ◦ Un flag nommé carry, qui vaut 1 si la dernière opération a réussi. Seules
  certaines opérations vont modifier le carry.
• Le numéro du joueur est généré par la machine ou spécifié au lancement, et est
fourni aux champions via le registre r1 de leur premier processus au démarrage.
Tous les autres registres sont mis à 0. Sauf le PC.
• Les champions sont chargés en mémoire de façon à espacer équitablement leurs
points d’entrée.
• La machine virtuelle va créer un espace mémoire dédié au combat des joueurs, puis
y charger les champions et leurs processus associés, et les exécuter séquentiellement
jusqu’à ce que mort s’ensuive.
• Tous les CYCLE_TO_DIE cycles, la machine doit s’assurer que chaque processus
a exécuté au moins un live depuis la dernière vérification. Un processus qui ne se
soumet pas à cette règle sera mis à mort à l’aide d’une batte en mousse virtuelle.
(Bonus bruitage !)
• Si au cours d’une de ces vérifications on se rend compte qu’il y a eu au moins
NBR_LIVE exécutions de live depuis la dernière vérification en date, on décrémente CYCLE_TO_DIE de CYCLE_DELTA unités.
• Quand il n’y a plus de processus en vie, la partie est terminée.
• Le gagnant est le dernier joueur qui a été rapporté comme étant en vie. La machine va ensuite afficher : "le joueur x(nom_champion) a gagne", où x est le numéro
du joueur et nom_champion le nom de son champion.
Exemple : "le joueur 2(rainbowdash) a gagne"
• A chaque exécution valide de l’instruction live, la machine doit afficher :
"un processus dit que le joueur x(nom_champion) est en vie"
• En tout état de cause, la mémoire est circulaire et fait MEM_SIZE octets.
• En cas d’erreur, vous devrez afficher un message pertinent sur la sortie d’erreur.
• Si on n’a pas décrémenté CYCLE_TO_DIE depuis MAX_CHECKS vérifications,
on le décrémente.
• La machine virtuelle se lance de la façon suivante :
> ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...
• -dump nbr_cycles
Au bout de nbr_cycles cycles d’exécution, dump la mémoire sur la sortie standard, puis quitte la partie. La mémoire doit être dumpée au format hexadécimal,
avec 32 octets par ligne.
• -n number
Fixe le numéro du prochain joueur. Si absent, le joueur aura le prochain numéro
libre dans l’ordre des paramètres. Le dernier joueur aura le premier processus dans
l’ordre d’exécution.
• Les champions ne peuvent pas dépasser CHAMP_MAX_SIZE, sinon c’est une
erreur.


Le champion
• Votre champion a trois objectifs indissociables : Faire en sorte que son joueur
soit rapporté comme "en vie", comprendre le sens de ladite vie, et annihiler ses
adversaires.
• Pour que son joueur soit dit comme "en vie", votre champion doit faire en sorte que
des live soient faits avec son numéro. Si l’un de ses processus fait un live avec
le numéro d’un autre joueur ... eh bien, c’est dommage, mais au moins un autre
joueur sera content. Si un processus d’un autre joueur fait des live avec votre
numéro, vous avez l’autorisation de vous moquer de lui et de profiter éhontément
de son erreur, tous en insultant sa famille en binaire.
• Absolument TOUTES les instructions sont utiles. Toutes les réactions de la machine, décrites plus loin dans le chapitre sur le langage, peuvent être utilisées
pour donner vie à votre champion et lui permettre de remporter dix-sept euros
cinquante-trois centimes au cours du championnat. Oui, même l’instruction aff
est utile, par exemple pour se moquer de l’ineptitude de vos adversaires.
• Il sera noté, à la soutenance, sur sa capacité à survivre à quelques challenges
élémentaires, comme vaincre un champion au Q.I de pot de fleurs, réussir à finir
une assiette de tarte aux pommes de ma grand-mère, ou dessiner des fleurs dans
un cappucino.
• Vous pourrez, plus tard, réaliser un nouveau champion qui sera destiné à participer
au championnat, (Rappel : C’est un autre projet !) et se battre contre les champions de vos camarades, et peut-être même ceux du Bocal, chose qui transformera
probablement assez rapidement votre champion en tas informe de boyaux virtuels,
mais qui pourrait bien, au prix d’une ou deux cérémonies vaudou impliquant des
épingles à nourrice et un endroit que l’honnêteté et la décence m’interdisent
de préciser davantage, vous couvrir de gloire et de chatons.

Le langage et la compilation
  Le langage assembleur
• Le langage assembleur est composé d’une instruction par ligne.
• Une instruction se compose de trois éléments : Un label (optionnel), composé
d’une chaîne de caractères parmi LABEL_CHARS suivi par LABEL_CHAR ; un
opcode ; et ses paramètres, séparés par SEPARATOR_CHAR. Un paramètre peut
être de trois types :
◦ Registre : (r1 <–> rx avec x = REG_NUMBER)
◦ Direct : Le caractère DIRECT_CHAR suivi d’une valeur numérique ou d’un
label (précédé par LABEL_CHAR), ce qui représente une valeur directe.
◦ Indirect : Une valeur ou un label (précédé de LABEL_CHAR), ce qui représente la valeur qui se trouve à l’adresse du paramètre, relativement au PC du
processus courant.
• Un label peut n’avoir aucune instruction à sa suite, ou être placé sur la ligne
d’avant l’instruction qu’il concerne.
• Le caractère COMMENT_CHAR démarre un commentaire.
• Un champion comportera également un nom et une description, qui sont présents
sur une ligne après les marqueurs NAME_CMD_STRING et COMMENT_CMD_STRING.
• Tous les adressages sont relatifs au PC et à IDX_MOD sauf pour lld, lldi et
lfork.
• Le nombre de cycles de chaque instruction, leur représentation mnémonique, leur
nombre de paramètres et les types de paramètres possibles sont décrits dans le
tableau op_tab déclaré dans op.c. Les cycles sont toujours consommés.
• Tous les autres codes n’ont aucune action a part passer au suivant et perdre un
cycle.
• lfork : Ca signifie long-fork, pour pouvoir fourcher de la paille à une distance
de 15 mètres, exactement comme son opcode. Pareil qu’un fork sans modulo à l’adresse.
• sti : Opcode 11. Prend un registre, et deux index (potentiellement des registres).
Additionne les deux derniers, utilise cette somme comme une adresse ou sera copiée
la valeur du premier paramètre.
• fork : Pas d’octet de codage des paramètres, prend un index, opcode 0x0c. Crée
un nouveau processus, qui hérite des différents états de son père, à part son PC,
qui est mis à (PC + (1er paramètre % IDX_MOD)).
• lld : Signifie long-load, donc son opcode est évidemment 13. C’est la même chose
que ld, mais sans % IDX_MOD. Modifie le carry.
• ld : Prend un paramètre quelconque et un registre. Charge la valeur du premier
paramètre dans le registre. Son opcode est 10 en binaire, et il changera le carry.
• add : Opcode 4. Prend trois registres, additionne les 2 premiers, et met le résultat
dans le troisième, juste avant de modifier le carry.
• zjmp : Il n’y a jamais eu, n’y a pas, et n’y aura jamais d’octet de codage des
paramètres derrière cette opération dont l’opcode est de 9. Elle prendra un index,
et fait un saut à cette adresse si le carry est à 1.
• sub : Pareil que add, mais l’opcode est 0b101, et utilise une soustraction.
• ldi : ldi, comme son nom l’indique, n’implique nullement de se baigner dans de
la crème de marrons, même si son opcode est 0x0a. Au lieu de ça, ca prend 2 index
et 1 registre, additionne les 2 premiers, traite ca comme une adresse, y lit une
valeur de la taille d’un registre et la met dans le 3eme.
• or : Cette opération est un OU bit-à-bit, suivant le même principe que and, son
opcode est donc évidemment 7.
• st : Prend un registre et un registre ou un indirect, et stocke la valeur du registre
vers le second paramètre. Son opcode est 0x03. Par exemple, st r1, 42 stocke la
valeur de r1 à l’adresse (PC + (42 % IDX_MOD))
• aff : L’opcode est 10 en hexadécimal. Il y a un octet de codage des paramètres,
même si c’est un peu bête car il n’y a qu’un paramètre, qui est un registre, dont
le contenu est interprété comme la valeur ASCII d’un caractère à afficher sur la
sortie standard. Ce code est modulo 256.
• live : L’instruction qui permet à un processus de rester vivant. A également pour
effet de rapporter que le joueur dont le numéro est en paramètre est en vie. Pas
d’octet de codage des paramètres, opcode 0x01. Oh, et son seul paramètre est sur
4 octets.
• xor : Fait comme and avec un OU exclusif. Comme vous l’aurez deviné, son opcode
en octal est 10.
• lldi : Opcode 0x0e. Pareil que ldi, mais n’applique aucun modulo aux adresses.
Modifiera, par contre, le carry.
• and : Applique un & (ET bit-à-bit) sur les deux premiers paramètres, et stocke le
résultat dans le registre qui est le 3ème paramètre. Opcode 0x06. Modifie le carry.
Encodage
Chaque instruction est encodée par :
• Le code de l’instruction (on le trouve dans op_tab).
• L’octet de codage des paramètres, si c’est approprié. À faire comme le montrent
les exemples suivants :
◦ r2,23,%34 donne l’octet de codage 0b01111000, soit 0x78
◦ 23,45,%34 donne l’octet de codage 0b11111000, soit 0xF8
◦ r1,r3,34 donne l’octet de codage 0b01011100, soit 0x5C
• Les paramètres, directement, selon le modèle suivant :
◦ r2,23,%34 donne l’OCP 0x78 puis 0x02 0x00 0x17 0x00 0x00 0x00 0x22
◦ 23,45,%34 donne l’OCP 0xF8 puis 0x00 0x17 0x00 0x2d 0x00 0x00 0x00
0x22
Quelques notes importantes :
• L’exécutable commence toujours par un header, défini dans op.h par le type
header_t
• La machine virtuelle est BIG ENDIAN. Demandez à Google ce que cela veut dire.
Exécution des champions
• La machine virtuelle est supposée émuler une machine parfaitement parallèle.
• Mais pour des raisons d’implémentation, on supposera que chaque instruction
s’exécute entièrement a la fin de son dernier cycle et attend durant toute sa durée. Les instructions qui se terminent à un même cycle s’exécutent dans l’ordre
décroissant des numéros de processus.
• Oui, le dernier né joue en premier.
