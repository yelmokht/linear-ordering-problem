#!/bin/Rscript

library(ggplot2)

correlation_plots <- function(source_path, output_path) {
    files <- list.files(source_path, pattern = "*.txt", full.names = TRUE)
    data <- array(0, c(length(files), 78))

    for (i in 1:length(files)) {
        file_path <- paste(files[i], sep="")
        data[i,] <- (read.table(file_path)$V4)
    }

    ils_data <- data.frame(value = data[1,])
    ma_data <- data.frame(value = data[2,])
    print(ma_data)
  
    # Plot
    plot <- ggplot() +
        geom_point(data = ils_data, aes(x = value, y = value, color = "ILS")) +
        geom_point(data = ma_data, aes(x = value, y = value, color = "MA")) +
        labs(x = "ILS", y = "MA") +
        ggtitle("Correlation plot of the average relative percentage deviation")
  
    # Save the plot
    ggsave(file.path(output_path, "correlation_plots.png"), plot)
}


args <- commandArgs(trailingOnly = TRUE)
source_path <- args[1]
output_path <- args[2]

correlation_plots(source_path, output_path)
