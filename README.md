# BUT-SAE-1.02-Systeme-vote-CPP

![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg?style=flat-square&logo=c%2B%2B)
![Qt Creator / qmake](https://img.shields.io/badge/Build-qmake%20%2F%20Qt%20Creator-41CD52.svg?style=flat-square&logo=qt)
![License](https://img.shields.io/badge/License-Academic-lightgrey.svg?style=flat-square)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen.svg?style=flat-square)

Projet académique réalisé dans le cadre de la **SAE 1.02 (Comparaison d'approches algorithmiques)** en BUT Informatique. Ce projet a pour objectif d'implémenter et de comparer différents modes de scrutin et systèmes de vote en **C++17**.

---

## 👥 Auteurs

- **Ayoub HSSINI** (`bouyaninho@gmail.com`)
- **Adam MANKAI** (`mankaiadam145@gmail.com`)
- **Mathias MALLET** (`mathias.m2502@gmail.com`)
- **Aurèle JAMBERT** (`aurele.jambert0@gmail.com`)

---

## 📌 Présentation des Systèmes de Vote

Le projet modélise trois algorithmes de vote distincts :

### 1. Scrutin Majoritaire à Deux Tours (`majoritaire/`)
- **Principe** : Reproduction du système d'élection présidentielle française. 
- Au premier tour, les votes exprimés pour chaque candidat sont comptabilisés.
- Les deux candidats arrivés en tête sont qualifiés pour le second tour, et le vainqueur est celui recueillant la majorité des suffrages au second tour.

### 2. Méthode d'Hondt de la plus forte moyenne (`hondt/`)
- **Principe** : Mode de scrutin proportionnel plurinominal utilisé notamment pour l'élection des eurodéputés au Parlement européen.
- Les suffrages obtenus par chaque liste sont successivement divisés par $1, 2, 3, \dots, N$ (où $N$ est le nombre total de sièges à pourvoir).
- Les quotients obtenus sont classés par ordre décroissant (implémenté via un tri par bulles adapté), et les sièges sont alloués aux plus fortes moyennes.

### 3. Vote Préférentiel / Borda Amélioré (`preferentiel/`)
- **Principe** : Vote alternatif par classement (ordre de préférence des candidats).
- Une méthode de **Borda quadratique** est appliquée : pour $k$ candidats, le candidat classé au 1er rang reçoit $k^2$ points, le 2ème $(k-1)^2$ points, etc.
- Le candidat ayant cumulé le plus grand total de points est désigné vainqueur.

---

## 📂 Structure du Répertoire

```text
.
├── Système de vote/
│   ├── hondt/                   # Implémentation du scrutin à la proportionnelle (d'Hondt)
│   │   ├── main.cpp             # Code source C++
│   │   ├── hondt.pro            # Configuration du projet qmake / Qt Creator
│   │   ├── entree1.txt          # Données de test (jeu d'entrée 1)
│   │   ├── entree2.txt          # Données de test (jeu d'entrée 2)
│   │   ├── oracle_1.txt         # Sortie attendue (oracle 1)
│   │   └── oracle_2.txt         # Sortie attendue (oracle 2)
│   ├── majoritaire/             # Implémentation du scrutin majoritaire à deux tours
│   │   ├── main.cpp             # Code source C++
│   │   ├── majoritaire.pro      # Configuration du projet qmake / Qt Creator
│   │   ├── entree1.txt          # Données de test (jeu d'entrée 1)
│   │   ├── entree2.txt          # Données de test (jeu d'entrée 2)
│   │   ├── oracle_1.txt         # Sortie attendue (oracle 1)
│   │   └── oracle_2.txt         # Sortie attendue (oracle 2)
│   ├── preferentiel/            # Implémentation du vote alternatif préférentiel (Borda amélioré)
│   │   ├── main.cpp             # Code source C++
│   │   ├── preferentiel.pro     # Configuration du projet qmake / Qt Creator
│   │   ├── entree1.txt          # Données de test (jeu d'entrée 1)
│   │   ├── entree2.txt          # Données de test (jeu d'entrée 2)
│   │   ├── oracle_1.txt         # Sortie attendue (oracle 1)
│   │   └── oracle_2.txt         # Sortie attendue (oracle 2)
│   └── sae 1.02 - RAPPORT.pdf   # Rapport détaillé de la SAE
└── README.md
```

---

## 🛠️ Compilation et Exécution

Les projets sont configurés avec **qmake** pour **Qt Creator** mais peuvent également être compilés directement en ligne de commande avec `g++` ou `clang++` (support C++17).

### Méthode 1 : Ligne de commande (`g++`)

Pour compiler et tester l'un des programmes (exemple avec le vote majoritaire) :

```bash
cd "Système de vote/majoritaire"

# Compilation
g++ -std=c++17 -Wall -Wextra main.cpp -o majoritaire

# Exécution avec redirection de fichier en entrée standard
./majoritaire < entree1.txt
```

Pour la méthode d'Hondt :
```bash
cd "Système de vote/hondt"
g++ -std=c++17 -Wall -Wextra main.cpp -o hondt
./hondt < entree1.txt
```

Pour le vote préférentiel :
```bash
cd "Système de vote/preferentiel"
g++ -std=c++17 -Wall -Wextra main.cpp -o preferentiel
./preferentiel < entree1.txt
```

### Méthode 2 : Avec Qt Creator

1. Ouvrez **Qt Creator**.
2. Ouvrez le fichier de projet souhaité (`.pro`) :
   - `Système de vote/hondt/hondt.pro`
   - `Système de vote/majoritaire/majoritaire.pro`
   - `Système de vote/preferentiel/preferentiel.pro`
3. Configurez le projet avec votre kit C++ habituel.
4. Dans l'onglet **Projets** > **Exécution**, vous pouvez cocher **"Exécuter dans un terminal"** ou configurer la redirection d'entrée avec l'un des fichiers `entree*.txt`.

---

## 🧪 Données de Test et Oracles

Chaque dossier contient deux jeux de données de test (`entree1.txt`, `entree2.txt`) ainsi que leurs oracles correspondants (`oracle_1.txt`, `oracle_2.txt`) permettant de valider les sorties et le bon comportement algorithmique des programmes.
