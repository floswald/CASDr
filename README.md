# CASDr

<!-- badges: start -->
[![R build status](https://github.com/floswald/CASDr/workflows/R-CMD-check/badge.svg)](https://github.com/floswald/CASDr/actions)
<!-- badges: end -->

[https://www.casd.eu](https://www.casd.eu) is the secure data platform for French Admin data. This packages wants to collect a set of `R` tools which researchers may find useful.

## Why Does The World Need This Package

* Thousands of researchers work with CASD data, each of them rolling their own version of code which performs the same task.
* This means we don't promote best practices efficiently.
* It means that we don't catch bugs.
* In an ideal world, there would be one package with a set of tested tools that each researcher can apply to have copied into their project space on the system from github or CRAN, and base their work on this.

*This does not necessarily have to be this package. But it could be part of a start*


## What Tasks?

CASD hosts a huge number of datasets, many of them in several versions that vary over time. So which tasks?

1. Read a set of columns out of a certain SAS database.
2. Compute straight line distance between two vectors of lat-lon coordinates and other geospatial operations
3. General data cleaning of a certain database

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

## What does *Tested* mean

1. One would have to build fake datasets to test package functionality outside of CASD.
2. At the same time developers would have to continuously run the unit tests inside CASD, change the code base, and improve the package on github. 

## Is there any involvement of CASD

* No, not so far.


