# AutoMix Software

This project aims to create a virtual and intelligent DJ to help customers create their own mix so they can enjoy any music without interruption.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.  
See [deployment](#deployment) for notes on how to build and deploy the project on a live system.

### Prerequisites

This project was developed in C# and .NET under Microsoft Visual Studio 2017. No plugins are required.

Get Visual Studio [here](https://www.visualstudio.com/downloads/).

### Installing

Clone the repository on your computer.

```
git clone https://github.com/LesProjecteurs/AutomixSoftware.git
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

## Built With

 - [Visual Studio](https://www.visualstudio.com/) - The IDE used.

----------

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our coding style, and the process for submitting merge requests to us.

----------

## Authors

 - **Maxime STEVENOT** - *Project Manager* - <stevenot@ecole.ensicaen.fr>
 - **Guillaume HANNES** - *DevOps* - <hannes@ecole.ensicaen.fr>
 - **Jordan ERNULT** - *Developer* - <ernult@ecole.ensicaen.fr>
 - **Louis CARLIER** - *Developer* - <lcarlier@ecole.ensicaen.fr>
 - **Pierre GABON** - *Developer* - <gabon@ecole.ensicaen.fr>

## Contributors

 - **Niels HECQUARD** - *Developer* - <hecquard@ecole.ensicaen.fr>
 - **Raphael HERBERT** - *Developer* - <herbert@ecole.ensicaen.fr>
 - **Cedric MASSON** - *Developer* - <masson@ecole.ensicaen.fr>
 - **Richard NICOLAS** - *Developer* - <rnicolas@ecole.ensicaen.fr>
 - **Anaelle TROADEC** - *Developer* - <atroadec@ecole.ensicaen.fr>

----------

## License

Copyright (C) 2016 - 2018 LesProjecteurs

LesProjecteurs is a partnership between Maxime STEVENOT,
Guillaume HANNES, Jordan ERNULT, Louis CARLIER & Pierre GABON.

This project is licensed under MIT License - see the [LICENSE](LICENSE) file for details.