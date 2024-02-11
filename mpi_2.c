#include <mpi.h>
#include <stdio.h>
int main()
{
	//Initialize the MPI Environment
	MPI_Init(NULL,NULL);

	//Get the number of processes
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	//Get the rank of processes
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	//Get the name of the processor
	char proc_name[MPI_MAX_PROCESSOR_NAME];
	int name_len;
	MPI_Get_processor_name(proc_name, &name_len);

	//Print a hello world message
	printf("Hello world from processor : %s\n rank : %d\nout of %d processors\n\n", proc_name, world_rank, world_size);

	//Finalize the MPI Environment
	MPI_Finalize();
}