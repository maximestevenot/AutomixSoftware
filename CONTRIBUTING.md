# Contributing

## Files

### Source code

#### Coding style

We use english, so please use it everywhere in the project (messages, class names, doc, etc).  

Names of variables, functions/methods, classes and everything else have to be clear, even if the name is a little longer.  
Names of variables should not be a name of a type.

As much as possible, the source code should be a good documentation.  
Otherwise, you have to create documentation.

Following the [PEP (Python Enhancement Proposal) 20](https://www.python.org/dev/peps/pep-0020/) is a good thing, even if the project does not use the Python language.

More info [here](https://isocpp.org/wiki/faq/coding-standards) and [here](https://lefticus.gitbooks.io/cpp-best-practices/content/) on C++ best practices.

### Formatted text files

If you need to make a structured document, you should consider [Markdown](https://en.wikipedia.org/wiki/Markdown).  
For example, this document uses the Markdown syntax.

For longer texts or presentations, [LaTeX](http://latex-project.org/) and HTML+CSS(+JS) could be good options.

#### Markdown

A list item must be done with "-" (minus character) to avoid potential confusion with "*" that can be used for emphasizing.  
The extension of Markdown files must be "md" or "markdown", "mkd" is not widely recognized as Markdown so it must not be used.

## Licensing policy

You must release your contributions under the same [license](LICENSE.md) if you want them to be accepted upstream.

----------

## Git

### Installation

> **Note:**

> - git provides only a text shell interface. 
> - We recommend you to **install a graphical user interface** for it.
> - We personally like **[SourceTree](https://www.sourcetreeapp.com/)** for Windows and Mac or **[GitKraken](https://www.gitkraken.com/)** for all platforms.

#### Microsoft Windows and Apple OS X

Download it on [the official website](http://www.git-scm.com/downloads) and install it.

#### Debian

The above text should also work on derivatives of [Debian](https://www.debian.org/), like [Trisquel](https://trisquel.info/), [gNewSense](http://www.gnewsense.org/), Ubuntu and Mint.

You have to install the git package and its dependencies.  
You must have [SuperUser/root](https://en.wikipedia.org/wiki/Superuser) rights, that you can have with `su` or `sudo command`.  
You can use `apt-get install`, `aptitude install` (if [aptitude](https://wiki.debian.org/Aptitude) is installed) or a graphical user interface with [Synaptic](https://wiki.debian.org/Synaptic) (if it is installed).

#### Fedora, CentOS and RHEL

You have to install the git package and its dependencies.  
With SuperUser/root rights, you can use `yum install` or a graphical user interface with [Yum Extender](http://www.yumex.dk/) (if it is installed).  
[On Fedora version 22 and more, yum is apparently dead](http://dnf.baseurl.org/2015/05/11/yum-is-dead-long-live-dnf/).

### Use

If you do not know how to use it, you must read a documentation (like [the official one](http://www.git-scm.com/doc)).

Use `git status` to check that your modifications will be commited.  
You have to pull before push.

----------

## Git workflow

Please do all of your development in a *feature* branch. You should clone the repository normally, like this:

```
git clone https://gitlab.ecole.ensicaen.fr/stevenot/projet_2a.git
```

When you're ready to start working on a new feature, create a new branch from *develop* :

```
cd projet_2a
git checkout -b feature/your-feature develop
```

Write your code and when the feature is ready, merge *origin/develop* into your local branch :

```
git checkout develop
git pull
git checkout feature/your-feature
git merge develop
git status
```

When you have resolved all conflicts, you can push to *origin* :

```
git add <files-to-commit>
git rebase --continue
git push origin feature/your-feature
```

Then fill a *Merge Request* on your Gitlab UI and resume your work on a new branch.

----------

## Questions

If you have any question about the project please contact the project manager : **Maxime STEVENOT** - <maxime.stevenot@ecole.ensicaen.fr>

Some of our developers are more specialized in different fields of this project. For specific questions, please contact :

 - **Guillaume HANNES**, *Audio analysis* - <hannes@ecole.ensicaen.fr>
 - **Louis CARLIER**, *User Interface* - <lcarlier@ecole.ensicaen.fr>
 - **Pierre Gabon**, *Audio management* - <gabon@ecole.ensicaen.fr>