### Required

By following those steps, you'll install the application development environment

1. Clone Git repository:

  ```bash
  $ git clone git@github.com:phds/cgrasp.git
  ```
2. Install 
[`python`](https://www.python.org/)

3. Create a [`virtualenv`](https://virtualenv.pypa.io/en/latest/index.html) to host the application:
  You may need `sudo` to install `virtualenv` globally

  ```bash
  # install virtualenv tool manager via pip
  $ [sudo] pip install virtualenv
  # create a new virtualenv folder called venv
  $ virtualenv venv
  # activate your virtualenv!
  $ source venv/bin/activate
  ```

4. Install application dependencies via pip:
  **/!\ Be sure to have your virtualenv activated /!\\**
  This is stipulated by `(venv)` in front of your terminal prompt.

  ```bash
  (venv) $ pip install -r requirements.txt
  ```

5. Install [`GNU MPFR library`](http://www.mpfr.org/mpfr-current/mpfr.html#Installing-MPFR) to deal with floating points precision:

  

6. Install MPFR's dependencies:

  ```bash
  (venv) $ sudo apt-get install libmpfr-dev libmpfr-doc libmpfr4 libmpfr4-dbg
  ```