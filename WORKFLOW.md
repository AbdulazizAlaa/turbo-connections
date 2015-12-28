##Table of Contents

1. [Prerequisites](#prerequisites)
2. [Requirements](#requirements)
3. [Forking the repo](#forking-the-repo)
4. [Make new branch](#make-branch)


##Prerequisites

None. But if you want to understand what is going on and how to use it correctly, which is a thing you will do sooner or later and sooner would be better, I recommend reading the first 3 chapters of this online book [Git-Book](http://git-scm.com/book/en/v2)  which won’t take more than 2 to 3 hours reading.

[return to TOC](#table-of-contents)

##Requirements

Git installed.
Account on github.

[return to TOC](#table-of-contents)


##Forking the repo

First thing you need to do is fork the main repo on github, which means create a copy of the repo on your account on github. We need to fork because no one have write access to the main repo, so all your work will be on your forked repo where you have write access and you will issue pull requests when you need to update your work to the main repo.

####Follow these steps:
1. Open github and login.
2. Go to this url https://github.com/AbdulazizAlaa/turbo-connections
3. Click on fork up on the right

   <IMG 1>

4. Open git shell/bash/terminal.
5. Go to the directory where the local copy of your forked repo will exist in, this is where all your work will be in.
6. Type in terminal `git clone url` replace url with the one from the forked repo as shown below, this will create a local copy in the current directory
   <IMG 2>
7. Now we need to make this local/master branch pull from main/master and push to forked/master, type the follwoing replacing url in the second command with the url you used in `git clone`.  

    ```
git remote set-url origin https://github.com/AbdulazizAlaa/turbo-connections.git
git remote set-url --push origin url
```

Now you have created your local repo that is attached to both the main repo and the forked one.

**Note that in the local repo you should never manually make any changes to the master branch, it is only used to checkout feature branches from it**

[return to TOC](#table-of-contents)

##Make New Branch

We will use git Desktop in the next steps
you can download it from here : https://desktop.github.com/
follow images :

1. we create new branch
<img 3>

2. after working on code and do whatever changes , make new commit
<img 4>

3. Now we want we can publish to our Online forked repo
<img 5>

4. when we want to make a pull request to the Original Repo just click here
<img 6>
**Note if this didn't work you can go to the website and make it manual like that**
<img 7>

Repeat those steps every time you want to create a new brance  OR step 2-4 if you will continue working on current branch
**Note NEVER Work on mater branch**
[return to TOC](#table-of-contents)
