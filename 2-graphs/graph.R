# Imports
library(ggplot2)
library(ggthemes)
library(scales)


# set working directory
setwd("/home/nuno/Documents/core/jobs/past/sogive-cser/SoGive-CSER-evaluation-public/2-graphs")
SAVE_IMGS = TRUE

## A. First principles threshold.

df_low_bound <- read.csv("./samples/samples_low_bound.txt", header=FALSE)
df_low_bound <= as.data.frame(df_low_bound)
colnames(df_low_bound) = c("samples")

## A.1. Plot Full list of samples
title_text = "First principles threshold\nfor willingness to pay for existential risk prevention"
subtitle_text = "(full list of samples)"
label_x_axis = "Threshold for lower willingness to pay"
label_y_axis = "Density"
ggplot(df_low_bound, aes(x=samples)) +
  geom_density(alpha=0.5, fill="navyblue", size=0.2, adjust=0.2) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=label_y_axis
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )+
  scale_x_continuous(labels = unit_format(unit = "M$/bp", scale = 1e-6))
getwd() ## Working directory on which the file will be saved. Can be changed with setwd("/your/directory")
height = 5
width = floor(height*(1+sqrt(5))/2)
if(SAVE_IMGS) ggsave("imgs/lower_threshold.png", width=width, height=height)

## A.2. 90% confidence interval
low = 1493397.069429
high = 13197742.931800
title_text = "First principles threshold\nfor willingness to pay for existential risk prevention"
subtitle_text = "(90% confidence interval)"
label_x_axis = "Threshold for lower willingness to pay"
label_y_axis = "Density"
ggplot(df_low_bound, aes(x=samples)) +
  geom_density(alpha=0.5, fill="navyblue", size=0.1, adjust=0.3, trim=FALSE) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=element_blank()
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )+
  scale_x_continuous(labels = unit_format(unit = "M$/bp", scale = 1e-6), breaks=pretty_breaks(n=5), limits=c(low,high))
if(SAVE_IMGS) ggsave("imgs/lower_threshold_90_ci.png", width=width, height=height)

## A.3. Reciprocals (bp/M$ instead of M$/bp)
df_low_bound_r = 1/df_low_bound

### A.3.1. Full list of samples
title_text = "First principles threshold\nfor willingness to pay for existential risk prevention"
subtitle_text = "(full list of samples)"
label_x_axis = "Threshold for lower willingness to pay"
label_y_axis = "Density"
ggplot(df_low_bound_r, aes(x=samples)) +
  geom_density(alpha=0.5, fill="navyblue", size=0.2, adjust=0.2) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=label_y_axis
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )+
  scale_x_continuous(labels = unit_format(unit = "bp/M$", scale = 10^6))
if(SAVE_IMGS) ggsave("imgs/lower_threshold_r.png", width=width, height=height)

### A.3.2. 90% confidence interval
title_text = "First principles threshold\nfor willingness to pay for existential risk prevention"
subtitle_text = "(90% confidence interval)"
label_x_axis = "Threshold for lower willingness to pay"
label_y_axis = "Density"
ggplot(df_low_bound_r, aes(x=samples)) +
  geom_density(alpha=0.5, fill="navyblue", size=0.1, adjust=0.3, trim=FALSE) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=element_blank()
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )+
  scale_x_continuous(labels = unit_format(unit = "bp/M$", scale = 10e6), breaks=pretty_breaks(n=5), limits=c(1/high,1/low))
if(SAVE_IMGS) ggsave("imgs/lower_threshold_90_ci_r.png", width=width, height=height)

## B. AI community threshold

### B.1. AI safety community alone
df_ai_community <- read.csv("./samples/samples_ai_community.txt", header=FALSE)
df_ai_community <= as.data.frame(df_ai_community)
colnames(df_ai_community) = c("samples")

df_ai_community

### B.2. AI safety community alone | full distribution
ggplot() +
  geom_density(data=df_ai_community, aes(x=samples), alpha=0.5, fill="#800080", size=0.2, adjust=0.2) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=label_y_axis
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )+
  scale_x_continuous(labels = unit_format(unit = "bp/M$", scale = 1), limits=c(0, 5))

### B.2. AI safety community alone | cropped distribution
ggplot() +
  geom_density(data=df_ai_community, aes(x=samples), alpha=0.5, fill="#800080", size=0.2, adjust=0.2) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=label_y_axis
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )+
  scale_x_continuous(labels = unit_format(unit = "bp/M$", scale = 1), limits=c(0, 0.5))
if(SAVE_IMGS) ggsave("imgs/ai_community_threshold.png", width=width, height=height)


## C. CSER model
df_cser <- read.csv("./samples/samples_cost_effectiveness_cser_bps_per_million.txt", header=FALSE)
df_cser <= as.data.frame(df_cser)
colnames(df_cser) = c("samples")

ggplot() +
  geom_density(data=df_cser, aes(x=samples), alpha=0.5, fill="limegreen",color="limegreen", size=0.3, adjust=0.2) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=label_y_axis
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )+
  scale_x_continuous(labels = unit_format(unit = "bp/M$", scale = 1), limits=c(0, 20))
if(SAVE_IMGS) ggsave("imgs/cser_model.png", width=width, height=height)

## C. Comparison between CSER and thresholds.
df_low_bound_r$samples = df_low_bound_r$samples * 10e6

### C.1. CSER vs first principles | all samples
title_text = "First principles threshold\nfor willingness to pay for existential risk prevention"
subtitle_text = "(full list of samples)"
label_x_axis = "Threshold for lower willingness to pay"
label_y_axis = "Density"
ggplot() +
  geom_density(data=df_low_bound_r, aes(x=samples), alpha=0.5, fill="navyblue", size=0.2, adjust=1) +
  geom_density(data=df_cser, aes(x=samples), alpha=0.5, fill="limegreen", color="limegreen", size=0.2, adjust=1) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=label_y_axis
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )+
  scale_x_continuous(labels = unit_format(unit = "bp/M$", scale = 1))

### C.2.  CSER vs first principles | cropped interval
title_text = "First principles threshold\nfor willingness to pay for existential risk prevention"
subtitle_text = "(90%?)"
label_x_axis = "Threshold for lower willingness to pay"
label_y_axis = "Density"
ggplot() +
  geom_density(data=df_low_bound_r, aes(x=samples), alpha=0.5, fill="navyblue", size=0.2, adjust=1) +
  geom_density(data=df_cser, aes(x=samples), alpha=0.5, fill="limegreen", size=0.2, adjust=1) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=label_y_axis
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )+
  scale_x_continuous(labels = unit_format(unit = "bp/M$", scale = 1), limits=c(0, 20))
if(SAVE_IMGS) ggsave("imgs/cser_vs_threshold.png", width=width, height=height)

ggplot() +
  geom_density(data=df_low_bound_r, aes(x=samples), alpha=0.5, fill="navyblue", size=0.2, adjust=1) +
  geom_density(data=df_cser, aes(x=samples), alpha=0.5, fill="limegreen", size=0.2, adjust=1) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=label_y_axis
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )+
  scale_x_continuous(labels = unit_format(unit = "bp/M$", scale = 1), limits=c(10, 20))
if(SAVE_IMGS) ggsave("imgs/cser_vs_threshold_tail.png", width=width, height=height)

ggplot() +
  geom_histogram(data=df_low_bound_r, aes(x=samples), alpha=0.5, fill="navyblue", size=0.2, adjust=1) +
  geom_histogram(data=df_cser, aes(x=samples), alpha=0.5, fill="limegreen", size=0.2, adjust=1) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=label_y_axis
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )+
  scale_x_continuous(labels = unit_format(unit = "bp/M$", scale = 1), limits=c(10, 50))
if(SAVE_IMGS) ggsave("imgs/cser_vs_threshold_tail.png", width=width, height=height)

ggplot() +
  geom_density(data=df_low_bound_r, aes(x=samples), alpha=0.5, fill="navyblue", size=0.2, adjust=1) +
  geom_density(data=df_cser, aes(x=samples), alpha=0.5, fill="limegreen", size=0.2, adjust=1) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=label_y_axis
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )+
  scale_x_continuous(labels = unit_format(unit = "bp/M$", scale = 1), trans="log2")
if(SAVE_IMGS) ggsave("imgs/cser_vs_threshold_logscale.png", width=width, height=height)

### C.4. CSER vs first principles | cropped intervals | without funging
df_cser_no_funging <- read.csv("./samples/samples_cost_effectiveness_cser_bps_per_million_no_funging.txt", header=FALSE)

df_cser_no_funging = as.data.frame(df_cser_no_funging)
colnames(df_cser_no_funging) = c("samples")

title_text = "First principles threshold\nfor willingness to pay for existential risk prevention"
subtitle_text = "(90%?)"
label_x_axis = "Threshold for lower willingness to pay"
label_y_axis = "Density"
ggplot() +
  geom_density(data=df_low_bound_r, aes(x=samples), alpha=0.5, fill="navyblue", size=0.2, adjust=0.2) +
  geom_density(data=df_cser_no_funging, aes(x=samples), alpha=0.5, fill="limegreen", size=0.2, adjust=0.2) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=label_y_axis
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )+
  scale_x_continuous(labels = unit_format(unit = "bp/M$", scale = 1), limits=c(0, 20))
if(SAVE_IMGS) ggsave("imgs/cser_vs_threshold_no_funging.png", width=width, height=height)

ggplot() +
  geom_density(data=df_low_bound_r, aes(x=samples), alpha=0.5, fill="navyblue", size=0.2) +
  geom_density(data=df_cser_no_funging, aes(x=samples), alpha=0.5, fill="limegreen", size=0.2) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=label_y_axis
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )+
  scale_x_continuous(labels = unit_format(unit = "bp/M$", scale = 1), trans="log2")
if(SAVE_IMGS) ggsave("imgs/cser_vs_threshold_no_funging_logscale.png", width=width, height=height)

## C.5. CSER vs AI safety community threshold.

## C.5.1. AI safety community vs cser | full
ggplot() +
  geom_density(data=df_ai_community, aes(x=samples), alpha=0.5, fill="#800080", size=0.2, adjust=0.2) +
  geom_density(data=df_cser, aes(x=samples), alpha=0.5, fill="limegreen", size=0.2, adjust=0.2) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=label_y_axis
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )+
  scale_x_continuous(labels = unit_format(unit = "bp/M$", scale = 1), limits=c(0, 10))
if(SAVE_IMGS) ggsave("imgs/cser_vs_ai_community_threshold_full.png", width=width, height=height)

## C.5.1. AI safety community vs cser | cropped
ggplot() +
  geom_density(data=df_ai_community, aes(x=samples), alpha=0.5, fill="#800080", size=0.2, adjust=0.2) +
  geom_density(data=df_cser, aes(x=samples), alpha=0.5, fill="limegreen", size=0.2, adjust=0.2) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=label_y_axis
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )+
  scale_x_continuous(labels = unit_format(unit = "bp/M$", scale = 1), limits=c(0, 1)) + scale_x_continuous (trans='log2')

if(SAVE_IMGS) ggsave("imgs/cser_vs_ai_community_threshold_zoomed.png", width=width, height=height)

## C.5.1. AI safety community vs cser | cropped
ggplot() +
  geom_density(data=df_ai_community, aes(x=samples), alpha=0.5, fill="#800080", size=0.2, adjust=0.2) +
  geom_density(data=df_cser, aes(x=samples), alpha=0.5, fill="limegreen", size=0.2, adjust=0.2) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=label_y_axis
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )+
  scale_x_continuous(labels = unit_format(unit = "bp/M$", scale = 1), trans='log2') 
if(SAVE_IMGS) ggsave("imgs/cser_vs_ai_community_threshold_log.png", width=width, height=height)

## D. Scratchpad

a = ifelse(runif(1) > 0.5, 1, 2)
b = ifelse(runif(1) > 0.1, 0.1, 100)

n=100
a_n = function(){
  a_draws = ifelse(runif(n) > 0.5, 1, 2)
  return(sum(a_draws))
}

b_n = function(){
  b_draws = ifelse(runif(n) > 0.1, 0.1, 100)
  return(sum(b_draws))
}

a_n_samples = replicate(10e5, a_n())
b_n_samples = replicate(2 * 10e5, b_n())

df_scratchpad = list()
df_scratchpad$a = a_n_samples
df_scratchpad$b = b_n_samples
df_scratchpad = as.data.frame(df_scratchpad)
df_scratchpad

p_scratchpad_1 <- ggplot(data=df_scratchpad) +
  geom_histogram(aes(x=a), alpha=0.5, fill="#800080", size=0.2) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=element_blank()
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )
if(SAVE_IMGS) ggsave("imgs/a_example.png", width=width, height=height)

p_scratchpad_2 <- ggplot(data=df_scratchpad) +
  geom_histogram(aes(x=b), fill="limegreen", alpha=0.5, size=0.2, binwidth = 100) +
  labs(
    title=element_blank(),
    subtitle=element_blank(),
    x=element_blank(), 
    y=element_blank()
  ) +
  theme_tufte() + 
  theme(
    legend.title = element_blank(),
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5), 
    legend.position="bottom",
    legend.box="vertical",
    axis.text.x=element_text(angle=60, hjust=1)
  )

if(SAVE_IMGS) ggsave("imgs/b_example.png", width=width, height=height)

library(cowplot)
plot_grid(p_scratchpad_1, p_scratchpad_2)

if(SAVE_IMGS) ggsave("imgs/a_b_example.png", width=width, height=height)
