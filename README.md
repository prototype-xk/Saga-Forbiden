🎮 Saga Forbidden

Un RPG 2D solo mêlant plusieurs univers inspirés de différents jeux vidéo. Explorez des dimensions uniques, combattez des ennemis et boss, gérez votre inventaire, craftez des objets et accomplissez des quêtes dans un monde riche et immersif.

![Status](https://img.shields.io/badge/status-en%20développement-yellow)
![SQL3](https://img.shields.io/badge/SQL3-3.2.26-blue)
![C++](https://img.shields.io/badge/C++-17-00599C?logo=cplusplus)

---

## 🎯 Objectif

Sortie sur Steam prévue avant le **31 décembre 2026**.

---

## 🧩 Description du jeu

- **RPG 2D solo** avec vue top-down (ou side-scrolling, à préciser si tu veux).
- **Combats** contre des ennemis et des boss, avec gestion de points de vie, esquives et attaques.
- **Système d'inventaire**, loot, craft, équipement et commerce avec PNJ.
- **Univers** composé de plusieurs dimensions aux règles et ambiances différentes.

---

## 🗂️ Structure du projet

```text
Saga-Forbidden/
└─ Saga-Forbidden/                 # Dossier du projet Visual Studio
   ├─ external/
   │   ├─ include/                 # Headers des dépendances (SDL3, SDL3_image, SDL3_ttf)
   │   └─ lib/                     # .lib / .dll / .pdb des dépendances
   ├─ Sage-Forbidden/              # Code du jeu
   │   ├─ assets/                  # Ressources (textures, sons, polices, maps...)
   │   ├─ include/                 # Headers du jeu
   │   │   ├─ Core/                # Application, gestion SDL, etc.
   │   │   ├─ Game/                # Boucle de jeu, états, logique globale
   │   │   └─ Entities/            # Joueur, ennemis, PNJ, etc.
   │   ├─ src/                     # Implémentations C++
   │   │   ├─ Core/
   │   │   ├─ Game/
   │   │   ├─ Entities/
   │   │   └─ main.cpp             # Point d'entrée du jeu
   │   └─ x64/                     # Binaires générés par Visual Studio (Debug/Release)
   ├─ Saga-Forbidden.sln           # Solution Visual Studio
   └─ x64/                         # Autres répertoires de build (selon la config VS)
```

---

## 🛠️ Stack technique

- **Langage** : C++17
- **Framework** : SDL3 (SDL3, SDL3_image, SDL3_ttf)
- **IDE** : Visual Studio
- **Plateforme cible** : Windows (d'autres plateformes possibles plus tard)

---

## 🗺️ Roadmap

### Phase 1 : Prototype Technique
- [ ] Initialisation SDL3
- [ ] Système de fenêtre et rendu
- [ ] Déplacement du personnage
- [ ] Gestion des inputs
- [ ] Chargement de textures

### Phase 2 : Système de Combat v1
- [ ] Entités ennemies de base
- [ ] Système de collision
- [ ] Combat au corps à corps
- [ ] Boss prototype
- [ ] Système de points de vie
- [ ] Animations d'attaque

### Phase 3 : Inventaire & Craft
- [ ] Interface d'inventaire
- [ ] Système de loot
- [ ] Recettes de craft
- [ ] Gestion des objets
- [ ] Système d'équipement

### Phase 4 : Quêtes & PNJ
- [ ] Système de dialogues
- [ ] PNJ interactifs
- [ ] Système de quêtes
- [ ] Commerce avec PNJ
- [ ] Journal de quêtes

### Phase 5 : Dimensions
- [ ] Système de portails
- [ ] Génération de mondes
- [ ] Transitions entre dimensions
- [ ] Sauvegarde par dimension
- [ ] Contenu unique par dimension

### Phase 6 : Polish & Préparation Steam
- [ ] Optimisation des performances
- [ ] Correction des bugs majeurs
- [ ] Équilibrage du gameplay
- [ ] Ajout d'effets visuels et sonores
- [ ] Interface utilisateur améliorée
- [ ] Intégration API Steam
- [ ] Système de sauvegarde cloud
- [ ] Achievements
- [ ] Page magasin Steam

### Phase 7 : Release
- [ ] Tests finaux
- [ ] Correction des derniers bugs
- [ ] Trailer de lancement
- [ ] Lancement officiel sur Steam

---

## 🚧 Statut

**Statut actuel** : Phase 1 – Prototype technique (Janvier 2026)

---

## 👤 Auteur

**Développé par** : Prototype  
**GitHub** : [@prototype-xk](https://github.com/prototype-xk)

---

> Si tu veux, tu peux aussi ajouter plus tard une section « Installation / Build » avec : version de Visual Studio, config x64, où copier les DLL SDL, etc., quand ton projet sera un peu plus stable.
