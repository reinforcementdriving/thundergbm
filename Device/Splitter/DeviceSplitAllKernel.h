/*
 * DeviceSplitAll.h
 *
 *  Created on: 15 May 2016
 *      Author: Zeyi Wen
 *		@brief: 
 */

#ifndef DEVICESPLITALL_H_
#define DEVICESPLITALL_H_

#include "../../DeviceHost/NodeStat.h"
#include "../../SharedUtility/DataType.h"
#include "../../Host/UpdateOps/SplitPoint.h"
#include "../../DeviceHost/BaseClasses/BaseSplitter.h"


__global__ void ComputeWeight(TreeNode *pAllTreeNode, TreeNode *pSplittableNode,
		  	  	  	  	  	  	  SplitPoint *pBestSplitPoint, nodeStat *pSNodeStat, real rt_eps, int flag_LEAFNODE,
		  	  	  	  	  	  	  real lambda, int numofSplittableNode, bool bLastLevel, int maxNumofSplittableNode);

__global__ void CreateNewNode(TreeNode *pAllTreeNode, TreeNode *pSplittableNode, TreeNode *pNewSplittableNode,
							  const SplitPoint *pBestSplitPoint,
		  	  	  	  	  	  	  int *pParentId, int *pLChildId, int *pRChildId,
		  	  	  	  	  	  	  const nodeStat *pLChildStat, const nodeStat *pRChildStat, nodeStat *pNewNodeStat,
		  	  	  	  	  	  	  int *m_nNumofNode, int *pNumofNewNode,
		  	  	  	  	  	  	  real rt_eps, int nNumofSplittableNode, bool bLastLevel, int maxNumofSplittableNode);


__global__ void GetUniqueFid(TreeNode *pAllTreeNode, TreeNode *pSplittableNode, int nNumofSplittableNode,
		 	 	 	 	 	 	 int *pFeaIdToBuffId, int *pUniqueFidVec,int *pNumofUniqueFid,
		 	 	 	 	 	 	 int maxNumofUsedFea, int flag_LEAFNODE, int *pnLock);

__global__ void InsToNewNode(const TreeNode *pAllTreeNode, const real *pdFeaValue, const int *pInsId,
		 	 	 	 	 	 const unsigned int *pFeaStartPos, const int *pNumofKeyValue,
		 	 	 	 	 	 const int *pSNIdToBuffId, const SplitPoint *pBestSplitPoint,
		 	 	 	 	 	 const int *pUniqueFidVec, const int *pNumofUniqueFid,
		 	 	 	 	 	 const int *pParentId, const int *pLChildId, const int *pRChildId,
		 	 	 	 	 	 int preMaxNodeId, int numofFea, int *pInsIdToNodeId, int numofIns, int flag_LEAFNODE);

__global__ void InsToNewNodeByDefault(TreeNode *pAllTreeNode, int *pInsIdToNodeId, const int *pSNIdToBuffId,
		   	   	   	   	   	   	   	   	   int *pParentId, int *pLChildId, int *pRChildId,
		   	   	   	   	   	   	   	   	   int preMaxNodeId, int numofIns, int flag_LEAFNODE,
		   	   	   	   	   	   	   	   	   const SplitPoint *pBestSplitPoint);

__global__ void UpdateNewSplittable(TreeNode *pNewSplittableNode, nodeStat *pNewNodeStat, int *pSNIdToBuffId,
		   	   	   	   	   	   	   	    nodeStat *pSNodeStat, int *pNumofNewNode, int *pBuffIdVec,
		   	   	   	   	   	   	   	    int *pBuffIdCounter, int maxNumofSplittable, int *pnLock, int preMaxNodeId);

#endif /* DEVICESPLITALL_H_ */
