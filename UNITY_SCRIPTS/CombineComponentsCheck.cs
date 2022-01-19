using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CombineComponentsCheck : MonoBehaviour
{
    public bool IsOnWorkbench;
    public Transform WorkbenchCheck;
    public float SphereRadius = 0.4f;
    public LayerMask WorkbenchMask; 
    public bool Craftable;
    
    void Update()
    {
        HotComponents hotComponents = GetComponent<HotComponents>();
        IsOnWorkbench = Physics.CheckSphere(WorkbenchCheck.position,SphereRadius,WorkbenchMask);

        if (hotComponents!=null)
        {
            if (IsOnWorkbench && gameObject.GetComponent<HotComponents>().cold)
            {
                Craftable=true;
            }
        }
        else
        {
            if (IsOnWorkbench)
            {
                Craftable=true;
            }
        }

            if (!IsOnWorkbench)
            {
                Craftable=false;
            }
    }
}
