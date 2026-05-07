%% Part 5 
%% Plots Discrete PI closed loop step response 
clear 
clc

% import data from arduino
data = readmatrix('attempt6.txt');

% extract time values versus 
t = data(:, 1);


% extract y values 
y = data(:, 2);


% extract u values 
u = data(:, 3);

plot(t, u, '-r', 'MarkerFaceAlpha', 0.5)
hold on 
plot(t, y, '-b', 'MarkerFaceAlpha', 0.5)
% title()
% xlabel()
% ylabel()
% 

