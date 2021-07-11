# `CASDr` : `R` Tools for the secure CASD Environment

<!-- badges: start -->
![](man/figures/lifecycle-experimental.svg)
[![R build status](https://github.com/floswald/CASDr/workflows/R-CMD-check/badge.svg)](https://github.com/floswald/CASDr/actions)
<!-- badges: end -->

## CASD

[CASD](https://www.casd.eu) is the secure data platform for French Admin data. This is typical high-security data access system, which allows researchers to work on a remote server which can be accessed with fingerprint and card authentication. The remote server is not connected to the internet, and data export from the server is subject to statistical disclosure controls. 

## Why Does The World Need This Package

* Many researchers work with CASD data, each of them rolling their own version of code which performs very similar tasks.
* This means we don't promote best practices efficiently.
* It means that we don't catch bugs.
* It means we cannot *ever* work on our code without being connected to the system. Many tasks involve testing code to work as expected, *before* one uses it on the actual data.
* It means *everybody* who starts working on the system has to pay an important setup cost, finding out how to do `X`.
* In an ideal world, there would be one package with a set of **tested tools** that each researcher can apply to have copied into their project space on the system from github or CRAN, and base their work on this.

*It does not necessarily have to be this package. But it could be part of a start.*



## What this Package Could Deliver

Imagine the following rosy scenario:

1. You obtain money and security clearance via the committee du secret statistique to work on some data on CASD. Suppose DADS - what else?
2. You have of course no idea how to even load the damn thing. It's in SAS.
3. Imagine you had a website like this one here, where a simple vignette would show in a worked example how to load this step by step?
4. Imagine it would go further and introduce you to some of more finicky details and tips and tricks in order to achieve a certain task.




## Which Tasks?

CASD hosts a huge number of datasets, many of them in several versions that vary over time. So which tasks?

1. Read a set of columns out of a certain SAS database.
2. Compute straight line distance between two vectors of lat-lon coordinates and other geospatial operations.
3. General data cleaning of a certain database.

## But ... User-specific Requirements?

*Each project has unique data cleaning requirements*

* If one could provide a standardized interface that builds a default version of a certain dataset, this would be a major achievement. 
* For example, suppose I want to read the French Census from the SAPHIR version for a certain year. One could use

```R
loadRP(year = 2015, ... )
```
where `...` would hold keywords on which to subset the census. 

* Of course each dataset will need a different method like the above, so there is a lot of custom code to write.

**The key difference is that all researchers could agree on the best version of this custom code and share with others**.

## What does *Tested* mean?

We want to run automated unit tests on code we use on CASD like here on github actions: [![R build status](https://github.com/floswald/CASDr/workflows/R-CMD-check/badge.svg)](https://github.com/floswald/CASDr/actions)

> But CASD is an offline environment!

Correct:

1. One would have to build fake datasets to test package functionality outside of CASD. No single bite of sensitive data needs to be exported from CASD.
2. One would have to setup a way that allows to import the R package _into_ CASD at a certain regular frequency. It's generally no problem to import code onto one's user space.
3. We would then run the same unit tests inside CASD, make changes to the code on github. Rinse, and repeat.

## Is there any involvement of CASD

* No, not so far.


