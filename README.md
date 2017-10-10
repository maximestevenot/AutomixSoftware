# AutoMix Software

This project aims to create a virtual and intelligent DJ to help customers create their own mix so they can enjoy any music without interruption.

## Development version

[![build status](https://gitlab.ecole.ensicaen.fr/stevenot/projet_2a/badges/develop/build.svg)](https://gitlab.ecole.ensicaen.fr/stevenot/projet_2a/commits/develop)

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.  
See [deployment](#deployment) for notes on how to build and deploy the project on a live system.

### Prerequisites

This project was developed in C# and .NET under Microsoft Visual Studio 2017. No plugins are required.

Get Visual Studio [here](https://www.visualstudio.com/downloads/).

### Installing

Clone the repository on your computer.

```
git clone https://gitlab.ecole.ensicaen.fr/stevenot/projet_2a.git
```

Open solution in Visual Studio.

```
File > Open > Project/Solution > "[...]/Automix Software.sln"
```

Run solution in *Debug* mode and under *Any CPU* architecture.

----------

## Deployment

Open a command prompt for Visual Studio and navigate to the *Automix Software* folder in the repository.
```
msbuild /m /nologo /p:Configuration=Release;Platform="Any CPU" "Automix Software.sln"
```
The .exe file will be built in the *Release* directory.

----------

## Project Follow-Up

To view the project meetings reports or any other document not relative to the source code and documentation, please checkout to the **[suivi_projet](https://gitlab.ecole.ensicaen.fr/stevenot/projet_2a/tree/suivi_projet/Suivi%20de%20projet)** branch.  
This branch contains all the needed files for the project follow-up.

----------

## Built With

 - [Visual Studio](https://www.visualstudio.com/) - The IDE used.

----------

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our coding style, and the process for submitting merge requests to us.

----------

## Authors

 - **Maxime STEVENOT** - *Project Manager* - <maxime.stevenot@ecole.ensicaen.fr>
 - **Guillaume HANNES** - <hannes@ecole.ensicaen.fr>
 - **Jordan ERNULT** - <ernult@ecole.ensicaen.fr>
 - **Louis CARLIER** - <lcarlier@ecole.ensicaen.fr>
 - **Pierre GABON** - <gabon@ecole.ensicaen.fr>

### Tutors

 - **Baptiste HEMERY** - <baptiste.hemery@ensicaen.fr>
 - **Estelle CHERRIER** - <estelle.cherrier@ensicaen.fr>

----------

## License

For Automix Software  
Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
This project is licensed under Proprietary License - see the [LICENSE.md](LICENSE.md) file for details.