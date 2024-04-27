#!/bin/Rscript

statistical_tests <- function(folder_path, output_path) {
    files <- list.files(folder_path, pattern="*.txt")
    solutions <- array(0, c(length(files), 78))

    for (i in 1:length(files)) {
        file_path <- paste(folder_path, files[i], sep="")
        solutions[i,] <- (read.table(file_path)$V4)
    }
    student_table <- array(0, c(length(files), length(files)))
    wilcoxon_table <- array(0, c(length(files), length(files)))

    for (i in 1:(length(files) - 1)) {
        for (j in (i+1):length(files)) {
            student_table[i, j] <- as.numeric(format(t.test(solutions[i,], solutions[j,], paired=T)$p.value, scientific = TRUE, digits = 3))
            wilcoxon_table[i, j] <- as.numeric(format(wilcox.test(solutions[i,], solutions[j,], paired=T)$p.value, scientific = TRUE, digits = 3))
        }
    }

    write.table(student_table, paste(output_path, "student_t_test.txt"))
    write.table(wilcoxon_table, paste(output_path, "wilcoxon_test.txt"))

    file_conn <- file(paste(output_path, "student_t_test.txt"), open = "a")

    cat("\nStudent t-test:\n", file = file_conn)

    for (i in seq_along(files)) {
        cat(i, ": ", files[i], "\n", file = file_conn)
    }

    close(file_conn)

        file_conn <- file(paste(output_path, "wilcoxon_test.txt"), open = "a")

    cat("\nWilcoxon test\n", file = file_conn)

    for (i in seq_along(files)) {
        cat(i, ": ", files[i], "\n", file = file_conn)
    }

    close(file_conn)


}

statistical_tests("./statistics/experiments/", "./statistics/statistical_tests/")
