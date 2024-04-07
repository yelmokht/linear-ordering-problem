#!/bin/Rscript

statistical_tests <- function(folder_path, output_path) {
    files <- list.files(folder_path, pattern="*.txt")
    solutions <- array(0, c(length(files), 78))
    for (i in 1:length(files)) {
        file_path <- paste(folder_path, files[i], sep="")
        solutions[i,] <- (read.table(file_path)$V4) # Round to 5 decimal places
    }
    student_table <- array(0, c(length(files), length(files)))
    wilcoxon_table <- array(0, c(length(files), length(files)))
    for (i in 1:(length(files) - 1)) {
        for (j in (i+1):length(files)) {
            student_table[i, j] <- as.numeric(format(t.test(solutions[i,]+0.0001, solutions[j,]+0.001, paired=T)$p.value, scientific = TRUE, digits = 3))
            wilcoxon_table[i, j] <- as.numeric(format(wilcox.test(solutions[i,]+0.001, solutions[j,]+0.0001, paired=T)$p.value, scientific = TRUE, digits = 3))
        }
    }
    write.table(student_table, paste(output_path, "student_t_test.txt"))
    write.table(wilcoxon_table, paste(output_path, "wilcoxon_test.txt"))
}

statistical_tests("./statistics/experiments/", "./statistics/statistical_tests/")
