#!/bin/Rscript

library(ggplot2)

correlation_plots <- function(source_path, output_path) {
    files <- list.files(source_path, pattern = "*.txt", full.names = TRUE)
    data <- array(0, c(length(files), 78))

    # Read data from files into the 'data' array
    for (i in 1:length(files)) {
        file_path <- paste(files[i], sep="")
        data[i,] <- read.table(file_path)$V4
    }

    # Create data frames for ILS and MA
    ils_data <- data[1,]
    ma_data <- data[2,]

    # Calculate min and max values for both ILS and MA
    ils_min <- min(ils_data)
    ils_max <- max(ils_data)
    ma_min <- min(ma_data)
    ma_max <- max(ma_data)

    # Fit linear regression model
    model <- lm(ma_data ~ ils_data)

    # Extract coefficients
    intercept <- coef(model)[1]
    slope <- coef(model)[2]

    # Create the plot with adjusted axis limits
    plot <- ggplot() +
        geom_point(aes(x = ils_data, y = ma_data), shape = 21, color = "black", fill = "white", stroke = 0.2) +
        geom_abline(intercept = intercept, slope = slope, color = "red", linewidth = 0.2) +
        labs(x = "Relative deviation with ILS (%)", y = "Relative deviation with MA (%)") +
        ggtitle("Correlation plot of the average relative percentage deviation") +
        xlim(ils_min, ils_max) + ylim(ma_min, ma_max) +
        theme_linedraw()

    # Save the plot
    ggsave(file.path(output_path, "correlation_plot.png"), plot, width = 6, height = 4)
}



args <- commandArgs(trailingOnly = TRUE)
source_path <- args[1]
output_path <- args[2]

correlation_plots(source_path, output_path)
