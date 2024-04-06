best <- read.csv("../instances/bestSolutions.txt")
best <- best[order(best$Problem), ]



deviations <- function(name) {
    data <- read.csv(paste("../stats/", name, ".txt", sep=""), sep="\t")
    data <- data[order(data$filename), ]

    a <- 100 * (data$wsct - best$BS) / best$BS
}


times <- function(name) {
    data <- read.csv(paste("../stats/", name, ".txt", sep=""), sep="\t")
    data <- data[order(data$filename), ]

    a <- data$time
}


test1 <- function(data, nameA, nameB) {
    a <- data(nameA)
    b <- data(nameB)

    student <- t.test(a, b, paired=T)$p.value
    wilcoxon <- wilcox.test(a, b, paired=T)$p.value

    student <- sprintf("%f", student)
    wilcoxon <- sprintf("%f", wilcoxon)

    return(c(student, wilcoxon))
}


test <- function(nameA, nameB) {
    tDeviation <- test1(deviations, nameA, nameB)
    tTime <- test1(times, nameA, nameB)

    result <- c(nameA, nameB, tDeviation, tTime, "\n")

    return(cat(result, sep=" & "))
}


"1.1 (i)"
"random vs cw"
test("stats-random-sptranoes-first", "stats-cw-transpose-first")
test("stats-random-exchange-first", "stats-cw-exchange-first")
test("stats-random-insert-first", "stats-cw-insert-first")

test("stats-random-transpose-best", "stats-cw-transpose-best")
test("stats-random-exchange-best", "stats-cw-exchange-best")
test("stats-random-insert-best", "stats-cw-insert-best")


"1.1 (ii)"
"first vs best"
test("stats-random-transpose-first", "stats-random-transpose-best")
test("stats-random-exchange-first", "stats-random-exchange-best")
test("stats-random-insert-first", "stats-random-insert-best")

test("stats-srz-transpose-first", "stats-srz-transpose-best")
test("stats-srz-exchange-first", "stats-srz-exchange-best")
test("stats-srz-insert-first", "stats-srz-insert-best")


"1.1 (iii)"
"transpose vs exchange vs insert"
test("stats-random-transpose-first", "stats-random-exchange-first")
test("stats-random-transpose-first", "stats-random-insert-first")
test("stats-random-exchange-first", "stats-random-insert-first")

test("stats-random-transpose-best", "stats-random-exchange-best")
test("stats-random-transpose-best", "stats-random-insert-best")
test("stats-random-exchange-best", "stats-random-insert-best")

test("stats-srz-transpose-first", "stats-srz-exchange-first")
test("stats-srz-transpose-first", "stats-srz-insert-first")
test("stats-srz-exchange-first", "stats-srz-insert-first")

test("stats-srz-transpose-best", "stats-srz-exchange-best")
test("stats-srz-transpose-best", "stats-srz-insert-best")
test("stats-srz-exchange-best", "stats-srz-insert-best")



"1.2 2"
"random vs srz"
test("stats-random-vnd-transpose-exchange-insert-first", "stats-srz-vnd-transpose-exchange-insert-first")
test("stats-random-vnd-transpose-insert-exchange-first", "stats-srz-vnd-transpose-insert-exchange-first")


"vnd-transpose-exchange-insert vs vnd-transpose-insert-exchange"
test("stats-random-vnd-transpose-exchange-insert-first", "stats-random-vnd-transpose-insert-exchange-first")
test("stats-srz-vnd-transpose-exchange-insert-first", "stats-srz-vnd-transpose-insert-exchange-first")
