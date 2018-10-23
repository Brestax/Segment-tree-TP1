clear all; close all;
pkg load miscellaneous;
pkg load io;
pkg load optim;

graphics_toolkit gnuplot

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ExecutionTime = dlmread('../Pruebas/ExecutionTime.csv','\t',1,0);

ExecutionTime

plot(ExecutionTime(:,2), ExecutionTime(:,1));

return 
