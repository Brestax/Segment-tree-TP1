clear all; close all;
pkg load miscellaneous;
pkg load io;
pkg load optim;

graphics_toolkit gnuplot

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ExecutionTime = dlmread('../Pruebas/ExecutionTime.csv','\t',1,0);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Figure_Handler = figure(1);
set(Figure_Handler,'PaperUnits','inches','PaperPosition',[0 0 6 4 ]);

Axis_Handler = axes;
set(Axis_Handler,'Box','on','FontName','Arial','FontSize',9,'GridLineStyle','--','LineWidth',0.5,'TickDir','in');
hold on;
grid on;

semilogx(ExecutionTime(:,2),ExecutionTime(:,1),'-m.','LineWidth',1.5);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

axis([100 1000000 0.001 20]);

print('Tiempo de Ejeuion.png','-dpng');
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


return;
