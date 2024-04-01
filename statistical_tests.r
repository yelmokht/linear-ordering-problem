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
"rand vs srz"
test("stats-rand-transpose-first", "stats-srz-transpose-first")
test("stats-rand-exchange-first", "stats-srz-exchange-first")
test("stats-rand-insert-first", "stats-srz-insert-first")

test("stats-rand-transpose-best", "stats-srz-transpose-best")
test("stats-rand-exchange-best", "stats-srz-exchange-best")
test("stats-rand-insert-best", "stats-srz-insert-best")


"1.1 (ii)"
"first vs best"
test("stats-rand-transpose-first", "stats-rand-transpose-best")
test("stats-rand-exchange-first", "stats-rand-exchange-best")
test("stats-rand-insert-first", "stats-rand-insert-best")

test("stats-srz-transpose-first", "stats-srz-transpose-best")
test("stats-srz-exchange-first", "stats-srz-exchange-best")
test("stats-srz-insert-first", "stats-srz-insert-best")


"1.1 (iii)"
"transpose vs exchange vs insert"
test("stats-rand-transpose-first", "stats-rand-exchange-first")
test("stats-rand-transpose-first", "stats-rand-insert-first")
test("stats-rand-exchange-first", "stats-rand-insert-first")

test("stats-rand-transpose-best", "stats-rand-exchange-best")
test("stats-rand-transpose-best", "stats-rand-insert-best")
test("stats-rand-exchange-best", "stats-rand-insert-best")

test("stats-srz-transpose-first", "stats-srz-exchange-first")
test("stats-srz-transpose-first", "stats-srz-insert-first")
test("stats-srz-exchange-first", "stats-srz-insert-first")

test("stats-srz-transpose-best", "stats-srz-exchange-best")
test("stats-srz-transpose-best", "stats-srz-insert-best")
test("stats-srz-exchange-best", "stats-srz-insert-best")



"1.2 2"
"rand vs srz"
test("stats-rand-vnd-transpose-exchange-insert-first", "stats-srz-vnd-transpose-exchange-insert-first")
test("stats-rand-vnd-transpose-insert-exchange-first", "stats-srz-vnd-transpose-insert-exchange-first")


"vnd-transpose-exchange-insert vs vnd-transpose-insert-exchange"
test("stats-rand-vnd-transpose-exchange-insert-first", "stats-rand-vnd-transpose-insert-exchange-first")
test("stats-srz-vnd-transpose-exchange-insert-first", "stats-srz-vnd-transpose-insert-exchange-first")
