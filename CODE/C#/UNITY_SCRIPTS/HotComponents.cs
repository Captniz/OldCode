using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HotComponents : MonoBehaviour
{
    [SerializeField] [Range(0f, 1f)] float MeltingSensibility;
    MeshRenderer rend;
    Color ColdMaterial;
    [SerializeField] Color Rame;
    [SerializeField] Color Aluminum;
    public bool cold;

    void Awake()
    {
        rend = GetComponent<MeshRenderer>(); 
    }

    void OnCollisionEnter(Collision collisionInfo)
    {
        if (collisionInfo.collider.name == "Water")
        {
            if (gameObject.tag == "Rame")
            {
                ColdMaterial = Rame;
                rend.material.color = Color.Lerp(rend.material.color,ColdMaterial,MeltingSensibility);
                rend.material.DisableKeyword("_EMISSION");
            }
            if (gameObject.tag == "Aluminum")
            {
                ColdMaterial = Aluminum;
                rend.material.color = Color.Lerp(rend.material.color,ColdMaterial,MeltingSensibility);
                rend.material.DisableKeyword("_EMISSION");
            }
            cold = true;
        }
    }
}
