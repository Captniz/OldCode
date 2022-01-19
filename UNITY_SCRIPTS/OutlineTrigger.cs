using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OutlineTrigger : MonoBehaviour
{
    public float Smooth = 5;
    GameObject mainCamera;

    void Awake() {
        mainCamera = GameObject.FindWithTag ("MainCamera");
    }
    // Update is called once per frame
    void Update()
    {
        int x = Screen.width / 2;
        int y = Screen.height / 2;

        Ray ray = mainCamera.GetComponent<Camera>().ScreenPointToRay(new Vector3(x,y));
        RaycastHit hit;


        if (Physics.Raycast(ray, out hit))
        {
            GameObject GameObjHit = hit.collider.gameObject;
            GameObject obj =  this.gameObject;
            if (GameObjHit == obj){
                obj.GetComponent<Outline>().OutlineWidth = Mathf.Lerp( obj.GetComponent<Outline>().OutlineWidth,10f, Time.deltaTime * Smooth);
            }else{
                obj.GetComponent<Outline>().OutlineWidth = Mathf.Lerp( obj.GetComponent<Outline>().OutlineWidth,0f, Time.deltaTime * Smooth);
            }
        }        
    }
}
