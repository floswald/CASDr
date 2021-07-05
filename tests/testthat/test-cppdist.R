
library(Rdna)

context("testing c++ dist function")

# checkout https://www.movable-type.co.uk/scripts/latlong.html

#        longitude, latitude
pt1 <- c(2.386319,48.87733)
pt2 <- c(2.331454,48.84905)

test_that(paste0("dist of those 2 pts is is 5.009km"),{
    expect_equal(Rdna::geo_dist(pt1[2],pt1[1],pt2[2],pt2[1]),5.009,tolerance=0.1)
})

test_that(paste0("this is wrong: of those 2 pts is is 5.009km"),{
    expect_false(abs(Rdna::naive_dist(pt1[2],pt1[1],pt2[2],pt2[1])-5.009)<2)
})

test_that("count close to bataclan on a vector",{
    batalon <- c(2.3706158)
    batalat <- c(48.8630099)

    lon <- c(2.386319,2.331454,2.404691,2.373877)
    lat <- c(48.87733,48.84905,48.856008,48.862615)

    expect_equal(Rdna:::cppST_DWithin(batalat,batalon,list(latitude=lat,longitude=lon),5)[1], 4)
    expect_equal(Rdna:::cppST_DWithin(batalat,batalon,list(latitude=lat,longitude=lon),4)[1], 4)
    expect_equal(Rdna:::cppST_DWithin(batalat,batalon,list(latitude=lat,longitude=lon),1)[1], 1)

})

