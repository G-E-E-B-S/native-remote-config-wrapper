import { IRemoteConfig, IRemoteConfigListener } from "./IRemoteConfig";
export class RemoteConfigApi {

    private static remoteConfigDelegate: IRemoteConfig;

    static setDelegate(configDelegate: IRemoteConfig) {
        if(this.remoteConfigDelegate) {
            console.error("remote config already initialized!!");
            return;
        }
        this.remoteConfigDelegate = configDelegate;
    }

    // static setListener(listener: IRemoteConfigListener) {
    //     if(this.remoteConfigDelegate)
    //         this.remoteConfigDelegate.setListener(listener);
    //     else
    //         console.error("[setListener] remote config is not implemented for current platform!!");               
    // }

    static fetch(callback: Function): void {
        if(this.remoteConfigDelegate)
            this.remoteConfigDelegate.fetch(callback);
        else
            console.error("[fetch] remote config is not implemented for current platform!!");            
    }
}

