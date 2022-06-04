
#' Using a specific column of a data frame to plot a pie plot
#'
#' @param data a dataframe or tibble
#' @param ncol specific column, factor
#'
#' @return a figure as ggplot2 object
#' @export
#'
#' @importFrom ggplot2 ggplot geom_col theme aes element_text element_blank labs position_stack
#' @importFrom ggrepel geom_text_repel
#' @importFrom dplyr `%>%`
#'
#' @examples
#' my_pie(mtcars,ncol=2)
#' my_pie(diamonds,ncol=3)
#' my_pie(diamonds,ncol=3)+guides(fill="none")
my_pie <- function(data, ncol, title=""){
  plotdat <- as.data.frame(table(data[,ncol])) %>% dplyr::arrange(-Freq)
  plotdat$Label <- paste(plotdat$Var1, paste0("(",round(((plotdat$Freq/sum(plotdat$Freq))*100),2),"%)"))

  p <- ggplot(plotdat, aes (x="", y = Freq, fill = factor(Var1))) +
    geom_col(position = 'stack', width = 1) +
    geom_text_repel(aes(label = Label, x = 1.3),size=5,
                    position = position_stack(vjust = 0.5)) +
    theme_classic() +
    theme(plot.title = element_text(hjust=0.5),
          axis.line = element_blank(),
          axis.text = element_blank(),
          axis.ticks = element_blank()) +
    labs(fill = "Category",x = NULL,y = NULL) +
    coord_polar("y")+ggtitle(title)
  return(p)
}




#' Using a specific column of a data frame to plot a pie plot-v2
#'
#' @param data a dataframe or tibble
#' @param ncol specific column, factor
#'
#' @return a figure as ggplot2 object
#' @export
#'
#' @import ggplot2
#' @importFrom ggrepel geom_text_repel
#' @importFrom dplyr `%>%`
#'
#' @examples
#' my_pie2(mtcars,ncol=2)
#' my_pie2(diamonds,ncol=3)
#' my_pie2(diamonds,ncol=3)+guides(fill="none")
#my_pie2 = function(...){
#  my_pie(...);
#}
my_pie2=my_pie
